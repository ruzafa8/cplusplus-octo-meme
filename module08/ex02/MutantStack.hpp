#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

# include <stack>

template<typename T>
class MutantStack: public std::stack<T> {
	public:
		MutantStack();
		MutantStack(const MutantStack<T> &other);
		~MutantStack();
		MutantStack<T> &operator=(const MutantStack<T> &other);

		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		iterator begin();
		iterator end();
		const_iterator begin() const;
		const_iterator end() const;
};

# include "MutantStack.tpp"

#endif