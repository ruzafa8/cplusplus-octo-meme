#include "RPN.hpp"

RPN::RPN(): tokens(std::stack<int>()) {}

RPN::~RPN() {}

RPN::RPN(const RPN &other): tokens(other.tokens) {
	*this = other;
}

RPN &RPN::operator=(const RPN &other) {
	if (this != &other) {
		this->tokens = other.tokens;
	}
	return (*this);
}


bool RPN::validInput(const std::string &input) {
	std::string::const_iterator it = input.begin();
while (it != input.end()) {
	if (!isdigit(*it) && *it != '+' && *it != '-'
				&& *it != '/' && *it != '*' && *it != ' ') {
			return false;
		}
		it++;
	}
	return true;
}

void RPN::insertData(const std::string &input) {
	if (!validInput(input))
		throw InvalidOperatorException();

	std::string::const_iterator it = input.begin();
	while (it != input.end()) {
		if (isdigit(*it))
			this->tokens.push(*it - '0');
		else if (*it != ' ')
			executeOperator(*it);
		it++;
	}
}

void RPN::executeOperator(char op) {
	int res;
	int first = this->pop();
	int second = this->pop();
	switch (op) {
		case '+': res = second + first; break;
		case '-': res = second - first; break;
		case '*': res = second * first; break;
		case '/': res = second / first; break;
		default: throw InvalidOperatorException();
	}
	this->tokens.push(res);
}

int RPN::pop() {
	if (this->tokens.empty())
		throw EmptyStackException();
	int res = this->tokens.top();
	this->tokens.pop();
	return res;
}
