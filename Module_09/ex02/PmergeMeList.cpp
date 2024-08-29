#include "PmergeMe.hpp"

template <typename T>
void outputList(const std::list<T>& lst) {
    for (typename std::list<T>::const_iterator it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

list<int>	PmergeMe::mergeList(list<int> left, list<int> right) {
	lst_int_it left_it = left.begin();
	lst_int_it right_it = right.begin();
	list<int> ret;
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

list<int>	PmergeMe::mergeInsertSortList(list<int> left, list<int> right) {
	lst_int_it midPoint;

	if(left.size() > 1) {
		left = mergeInsertSortList(firstHalf(left), secondHalf(left));
	}
	if(right.size() > 1) {
		right = mergeInsertSortList(firstHalf(right), secondHalf(right));
	}
	return(mergeList(left, right));
}

list<int> PmergeMe::firstHalf(list<int> _lst) {
	list<int> ret;
	lst_int_it it = _lst.begin();
	int size = _lst.size();

	for(int i = 0; i < size / 2; i++) {
		ret.push_back(*it);
		it++;
	}
	return (ret);
}

list<int> PmergeMe::secondHalf(list<int> _lst) {
	list<int> ret;
	lst_int_it it = _lst.begin();
	int size = _lst.size();

	for(int i = 0; i < size / 2; i++) {
		it++;
	}
	while(it != _lst.end()) {
		ret.push_back(*it);
		it++;
	}
	return (ret);
}

void	PmergeMe::sortList() {
	list<int> left = firstHalf (this->lst);
	list<int> right = secondHalf(this->lst);
	this->lst = mergeInsertSortList(left, right);
}
