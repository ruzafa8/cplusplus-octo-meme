#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) {
	*this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other) {}
	return *this;
}

std::ostream &operator<<(std::ostream &os, std::vector<int> &v) {
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		os << *it << " ";
	}
	return os;
}
std::ostream &operator<<(std::ostream &os, std::deque<int> &d) {
	for (std::deque<int>::iterator it = d.begin(); it != d.end(); it++) {
		os << *it << " ";
	}
	return os;
}

bool PmergeMe::isNumber(const std::string &str) {
	if (str.empty() || str[0] == '-' || (str[0] == '+' && str.length() == 1))
		return false;
	for (size_t i = str[0] == '+' ? 1 : 0;i < str.length(); i++)
		if (!std::isdigit(str[i]))
			return false;
	return true;
}

void PmergeMe::sort(int argc, char **argv) {
	std::vector<int>	v;
	std::deque<int>		d;
	long				number;
    std::clock_t		clock;

	for (int i = 1; i < argc; i++) {
		if (!isNumber(argv[i]))
			throw std::invalid_argument("[ERROR] Invalid argument. Usage: ./PmergeMe <list of integer positive numbers>");
		number = std::strtol(argv[i], nullptr, 10);
		if (std::find(v.begin(), v.end(), number) != v.end())
            throw std::invalid_argument("[ERROR] Duplicates found!");
		v.push_back(number);
		d.push_back(number);
	}
	std::cout << "Before: " << v << std::endl;
    clock = std::clock();
    v = sortCollection(v);
    clock = std::clock() - clock;
    std::cout << "After: " << v << std::endl;
    std::cout << "Time to process a range of " << v.size() << " elements with std::vector<int> : ";
    std::cout << std::fixed << std::setprecision(5);
    std::cout << static_cast<double>(clock) / CYCLES_US << " us" << std::endl;

    clock = std::clock();
    d = sortCollection(d);
    clock = std::clock() - clock;
    std::cout << "Time to process a range of " << d.size() << " elements with std::deque<int> : ";
    std::cout << std::fixed << std::setprecision(5);
    std::cout << static_cast<double>(clock) / CYCLES_US << " us" << std::endl;
}

bool PmergeMe::isSorted(std::vector<int> &list) {
	int size = list.size();
	if (size == 1 || size == 0)
		return true;
	for (std::vector<int>::iterator it = list.begin(); it != list.end() && it + 1 != list.end(); it++) {
		if (*it >= *(it + 1))
			return (false);
	}
	return true;
}

bool PmergeMe::isSorted(std::deque<int> &list) {
	int size = list.size();
	if (size == 1 || size == 0)
		return true;
	for (std::deque<int>::iterator it = list.begin(); it != list.end() && it + 1 != list.end(); it++) {
		if (*it >= *(it + 1))
			return (false);
	}
	return true;
}

void PmergeMe::merge(std::vector<int> &list, int left, int mid, int right) {
	std::vector<int> leftSide(mid - left + 1);
	std::vector<int> rightSide(right - mid);

	std::vector<int>::iterator leftIt = leftSide.begin();
    std::vector<int>::iterator rightIt = rightSide.begin();


    for (int i = left; i < mid + 1; i++) {
        *leftIt = list[i];
        leftIt++;
    }
    
    for (int i = mid; i < right; i++) {
        *rightIt = list[i + 1];
        rightIt++;        
    }

	    leftIt = leftSide.begin();
    rightIt = rightSide.begin();
    
    int i = left;
    
    while (leftIt != leftSide.end() && rightIt != rightSide.end())
        list.at(i++) = *leftIt <= *rightIt ? *leftIt++ : *rightIt++;
    
    while (leftIt != leftSide.end())
        list[i++] = *leftIt++;

    while (rightIt != rightSide.end())
        list[i++] = *rightIt++;
}

void PmergeMe::merge(std::deque<int> &list, int left, int mid, int right) {
    std::deque<int> leftSide(mid - left + 1);
    std::deque<int> rightSide(right - mid);

    std::deque<int>::iterator leftIt = leftSide.begin();
    std::deque<int>::iterator rightIt = rightSide.begin();
    
    for (int i = left; i < mid + 1; i++) {
        *leftIt = list[i];
        leftIt++;
    }
    
    for (int i = mid; i < right; i++) {
        *rightIt = list[i + 1];
        rightIt++;        
    }

    leftIt = leftSide.begin();
    rightIt = rightSide.begin();
    
    int i = left;
    
    while (leftIt != leftSide.end() && rightIt != rightSide.end())
        list.at(i++) = *leftIt <= *rightIt ? *leftIt++ : *rightIt++;
    
    while (leftIt != leftSide.end())
        list[i++] = *leftIt++;

    while (rightIt != rightSide.end())
        list[i++] = *rightIt++;

}

std::vector<int> PmergeMe::sortCollection(std::vector<int> &list) {
    if (isSorted(list))
        return list;
        
    bool odd = list.size() % 2 == 1;
    int lastNumber = list.size() % 2 == 1 ? list.back() : 0;
    
    if (odd)
        list.pop_back();

    int len = list.size();
    std::vector<int> auxList(list);

    for (int currSize = 1; currSize < len; currSize *= 2) {
        for (int left = 0; left < len; left += 2 * currSize) {
            int mid = std::min(left + currSize - 1, len - 1);
            int right = std::min(left + 2 * currSize - 1 , len - 1);
            merge(auxList, left, mid, right);
        }
    }
    
    std::vector<int>::iterator it;
    
    if (odd) {
        it = std::upper_bound(auxList.begin(), auxList.end(), lastNumber);
        auxList.insert(it, lastNumber);
    }
    return auxList;

}

std::deque<int> PmergeMe::sortCollection(std::deque<int> &list) {
	if (isSorted(list))
        return list;
        
    bool odd = list.size() % 2 == 1;
    int lastNumber = list.size() % 2 == 1 ? list.back() : 0;
    
    if (odd)
        list.pop_back();

    int len = list.size();
    std::deque<int> auxList(list);

    for (int currSize = 1; currSize < len; currSize *= 2) {
        for (int left = 0; left < len; left += 2 * currSize) {
            int mid = std::min(left + currSize - 1, len - 1);
            int right = std::min(left + 2 * currSize - 1 , len - 1);
            merge(auxList, left, mid, right);
        }
    }
    
    std::deque<int>::iterator it;
    
    if (odd) {
        it = std::upper_bound(auxList.begin(), auxList.end(), lastNumber);
        auxList.insert(it, lastNumber);
    }
    return auxList;
}