#include "PmergeMe.hpp"

template <typename T>
void outputVec(const std::vector<T>& vect) {
    for (typename std::vector<T>::const_iterator it = vect.begin(); it != vect.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

vector<int>	PmergeMe::mergeVector(vector<int> left, vector<int> right) {
	vec_int_it left_it = left.begin();
	vec_int_it right_it = right.begin();
	vector<int> ret;
	while(left_it != left.end() || right_it != right.end()) {
		if(left_it == left.end()) {
			while(right_it != right.end()) {
				ret.push_back(*right_it);
				right_it++;
			}
		}
		else if(right_it == right.end()) {
			while(left_it != left.end()) {
				ret.push_back(*left_it);
				left_it++;
			}
		}
		else if(*left_it < *right_it) {
			ret.push_back(*left_it);
			left_it++;
		}
		else if(*right_it < *left_it){
			ret.push_back(*right_it);
			right_it++;
		}
	}
	return (ret);
}

vector<int>	PmergeMe::mergeInsertSortVector(vector<int> left, vector<int> right) {
	if(left.size() > 1) {
		left = mergeInsertSortVector(vector<int> (left.begin(), left.begin() + left.size() / 2), vector<int> (left.begin() + left.size() / 2, left.end()));
	}
	if(right.size() > 1) {
		right = mergeInsertSortVector(vector<int> (right.begin(), right.begin() + right.size() / 2), vector<int> (right.begin() + right.size() / 2, right.end()));
	}
	return(mergeVector(left, right));
}

void	PmergeMe::sortVector() {
	int mid = this->vec.size() / 2;
	this->vec = mergeInsertSortVector(vector<int> (this->vec.begin(), this->vec.begin() + mid), vector<int> (this->vec.begin() + mid, this->vec.end()));
}
