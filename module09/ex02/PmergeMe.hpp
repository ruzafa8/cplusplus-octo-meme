#ifndef PMERGE_ME_HPP
# define PMERGE_ME_HPP

# include <iostream>
# include <iomanip>
# include <deque>
# include <vector>
# include <ctime>

# define CYCLES_US CLOCKS_PER_SEC * 1e6


class PmergeMe {
	private:
		PmergeMe();
		~PmergeMe();
		static bool isNumber(const std::string &str);
		static std::vector<int> sortCollection(std::vector<int> &v);
		static std::deque<int> sortCollection(std::deque<int> &v);

		static bool isSorted(std::vector<int> &list);
		static bool isSorted(std::deque<int> &list);

		static void merge(std::vector<int> &list, int left, int mid, int right);
		static void merge(std::deque<int> &list, int left, int mid, int right);

	public:
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		static void sort(int argc, char **argv);
};

std::ostream &operator<<(std::ostream &os, std::vector<int> &v);
std::ostream &operator<<(std::ostream &os, std::deque<int> &d);

#endif
