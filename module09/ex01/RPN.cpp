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
	if (!isnumber(*it) && *it != '+' && *it != '-'
				&& *it != '/' && *it != '*' && *it != ' ') {
			return false;
		}
		std::cout << "si" << std::endl;
		it++;
	}
	return true;
}


void RPN::insertData(const std::string &input) {
	if (!validInput(input))
		throw InvalidOperatorException();

	std::string::const_iterator it = input.begin();
	while (it != input.end()) {
		if (isnumber(*it))
			this->tokens.push(*it - '0');
		else executeOperator(*it);
		it++;
	}
}

void RPN::executeOperator(char op) {
	int res;
	switch (op) {
		case '+': res = this->pop() + this->pop(); break;
		case '-': res = this->pop() - this->pop(); break;
		case '*': res = this->pop() * this->pop(); break;
		case '/': res = this->pop() / this->pop(); break;
		default: throw InvalidOperatorException();
	}
	this->tokens.push(res);
}

int RPN::pop() {
	int res = this->tokens.top();
	this->tokens.pop();
	return res;
}
