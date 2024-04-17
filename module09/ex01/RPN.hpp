#ifndef RPN_HPP
# define RPN_HPP

# include <string>
# include <stack>
# include <cstdlib>
# include <sstream>
# include <exception>
# include <iostream>

class RPN {
	private:
		std::stack<int> tokens;
		static bool validInput(const std::string &input);
		void executeOperator(char op);

	public:
		RPN();
		~RPN();
		RPN(const RPN &other);

		RPN &operator=(const RPN &other);

		void insertData(const std::string &input);
		int pop();

		class InvalidOperatorException: public std::exception {
			public:
				virtual const char *what() const throw() {
				return "The operator is not valid";
				}
		};	
};

#endif
