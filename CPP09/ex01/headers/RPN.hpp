/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:40:03 by andvieir          #+#    #+#             */
/*   Updated: 2024/01/04 15:40:03 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <algorithm>
# include <stack>
# include <fstream>
# include <sstream>

class RPN {

	private:
		std::string	_expr;
		std::stack<double>	_stack;
		RPN(const RPN & original);
		RPN & operator=(const RPN & original);


	public:
		RPN();
		RPN(std::string input);
		~RPN();

		void	setExpression(std::string input);
		std::string	getExpression() const;

		double	add(double n1, double n2);
		double	sub(double n1, double n2);
		double	mul(double n1, double n2);
		double	div(double n1, double n2);

		bool	isValidExpression();
		void	executeRPN();

		class InvalidExpressionException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

#endif
