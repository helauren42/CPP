#include "PmergeMe.hpp"

template <typename T>
void outputVec(const std::vector<T>& vect) {
    std::cout << "OUTPUT VEC:" << std::endl;
    for (typename std::vector<T>::const_iterator it = vect.begin(); it != vect.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

template <typename T1, typename T2>
void outputVecPair(const std::vector<std::pair<T1, T2>>& vect) {
    std::cout << "OUTPUT VEC PAIR:" << std::endl;
    for (typename std::vector<std::pair<T1, T2>>::const_iterator it = vect.begin(); it != vect.end(); ++it) {
        std::cout << it->first << " " << it->second << " ";
    }
    std::cout << std::endl;
}

void	PmergeMe::sortPairVector() {
	int odd = 0;
	if(this->vec.size() % 2)
		odd = 1;
	std::pair<int, int> _pair;

	for (vec_int_it it = this->vec.begin(); it <= this->vec.end() -1 -odd; it += 2) {
		if (*it < *(it + 1)) {
			_pair = std::make_pair(*it, *(it + 1));
		}
		else {
			_pair = std::make_pair(*(it + 1), *it);
		}
		this->vecPair.push_back(_pair);
	}
}

vec_pair_int	PmergeMe::mergeSortPairVector(vec_pair_int mini_vec) {
	if(mini_vec.size() < 2)
		return mini_vec;
	int mid_pos = mini_vec.size() / 2;
	vec_pair_int left;
	std::copy(mini_vec.begin(), mini_vec.begin() + mid_pos, std::back_inserter(left));
	vec_pair_int right;
	std::copy(mini_vec.begin() + mid_pos, mini_vec.end(), std::back_inserter(right));
	left = mergeSortPairVector(left);
	right = mergeSortPairVector(right);
	int i = 0, j = 0, k = 0;
	while(i < left.size() && j < right.size()) {
		if(left[i].second < right[j].second) {
			mini_vec[k] = left[i];
			i++;
		}
		else {
			mini_vec[k] = right[j];
			j++;
		}
		k++;
	}
	while(i < left.size()) {
		mini_vec[k] = left[i];
		i++; k++;
	}
	while(j < right.size()) {
		mini_vec[k] = right[j];
		j++; k++;
	}
	return mini_vec;
}

void	PmergeMe::unPairVector() {
	int		last = -1;
	int		size = this->vec.size();
	if(this->vec.size() % 2) {
		last = this->vec.back();
	}
	this->vec.clear();
	
	outputVecPair(this->vecPair);
	this->vec.push_back(this->vecPair.begin()->first);
	int i = 0;
	for(vec_pair_int::iterator it = this->vecPair.begin(); it != this->vecPair.end(); it++, i++) {
		if(i > 0) {
			this->vecTemp.push_back(this->vecPair[i].first);
		}
		this->vec.push_back(this->vecPair[i].second);
	}
	if(last != -1)
		this->vecTemp.push_back(last);
}

void PmergeMe::binarySearchVector(int element, int x_max) {
    int start = 0;
    int mid;

    while (start <= x_max) {
        mid = start + (x_max - start) / 2;
        if (this->vec[mid] < element)
            start = mid + 1;
        else
            x_max = mid - 1;
    }
    
    if (start < this->vec.size()) {
        if (element > this->vec[start])
            this->vec.insert(this->vec.begin() + start + 1, element);
        else
            this->vec.insert(this->vec.begin() + start, element);
    } else {
        this->vec.push_back(element);
    }
}

void	PmergeMe::JacobsthalInsert() {
	int	x = 1, y = 0;
	int x_max, y_max;

	for(vector<unsigned long>::iterator it = jacobsthal_diff.begin(); it != jacobsthal_diff.end(); it++) {
		x_max = x + *it;
		y_max = y + *it;
		if(y_max > this->vecTemp.size()) {
			break;
		}
		while(y_max-- != y) {
			this->binarySearchVector(this->vecTemp[y_max], x_max);
		}
		x += *it * 2;
		y += *it;
	}
	y_max = this->vecTemp.size();
	while (y_max-- != y)
		this->binarySearchVector(this->vecTemp[y_max], this->vec.size() - 1);
}

void	PmergeMe::sortVector() {
	this->sortPairVector();
	outputVecPair(this->vecPair);
	this->vecPair = this->mergeSortPairVector(this->vecPair);
	outputVecPair(this->vecPair);
	this->unPairVector();
	this->JacobsthalInsert();
}
