#ifndef MUTANT_STACK_TPP
# define MUTANT_STACK_TPP

# include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack(): std::stack<T>() {}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &other) {
	*this = other;
}

template<typename T>
MutantStack<T>::~MutantStack() {}

template<typename T>
MutantStack<T> &operator=(const MutantStack<T> &other) {}

#endif