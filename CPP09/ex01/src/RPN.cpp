/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:47:54 by andvieir          #+#    #+#             */
/*   Updated: 2024/01/04 15:47:54 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/RPN.hpp"

/* ===================== Orthodox Canonical Form ===================== */

RPN::RPN() : _expr("default") {
	executeRPN();
}

RPN::RPN(const RPN & original) {
	(void)original;
}
RPN & RPN::operator=(const RPN & original) {
	(void)original;
	return (*this);
}

RPN::~RPN() {}

/* ===================== Constructors ===================== */

RPN::RPN(std::string input) : _expr(input) {
	!isValidExpression() ? throw InvalidExpressionException() : 0;
	executeRPN();
}

/* ===================== Setter Functions ===================== */

void	RPN::setExpression(std::string input) {
	_expr = input;
}

/* ===================== Getter Functions ===================== */

std::string	RPN::getExpression() const {
	return (_expr);
}

/* ===================== Member Functions ===================== */

double	RPN::add(double n1, double n2) {
	return (n1 + n2);
}

double	RPN::sub(double n1, double n2) {
	return (n1 - n2);
}

double	RPN::mul(double n1, double n2) {
	return (n1 * n2);
}

double	RPN::div(double n1, double n2) {
	return (n1 / n2);
}

bool	RPN::isValidExpression() {
	std::istringstream	iss(_expr);
	std::string	index;
	while (iss >> index)
		if (!((index.size() == 1 && isdigit(index[0])) || (index.size() == 1 && std::string("+-*/").find(index[0]) != std::string::npos))) return false;
	return true;
}

void	RPN::executeRPN() {
	std::istringstream	iss(_expr);
	std::string	index;

	double (RPN::*expressionFunctions[4])(double n1, double n2) = {
		&RPN::add,
		&RPN::sub,
		&RPN::mul,
		&RPN::div
	};

	std::string	token[4] = { "+", "-", "*", "/" };

	while (iss >> index) {
		if (isdigit(index[0]))	_stack.push(std::atof(index.c_str()));
		else {
			if (_stack.empty())	throw InvalidExpressionException();
			double	value2 = _stack.top();
			_stack.pop();
			if (_stack.empty())	throw InvalidExpressionException();
			double	value1 = _stack.top();
			_stack.pop();

			for (int i = 0; i < 4; i++) {
				if (index[0] == *(token[i].c_str()))
					_stack.push((this->*expressionFunctions[i])(value1, value2));
				else if (std::string("+-*/").find(index[0]) == std::string::npos)
					throw InvalidExpressionException();
			}
		}
	}
	if (!_stack.empty()) std::cout << _stack.top() << std::endl;
}

/* ===================== Exceptions ===================== */

const char *RPN::InvalidExpressionException::what() const throw() {
	return ("Expression Error: Invalid Expression");
}
