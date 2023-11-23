/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:42:57 by andvieir          #+#    #+#             */
/*   Updated: 2023/11/06 10:42:57 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>
# include <string>
# include <fstream>
# include <iomanip>
# include <cmath>
# include <ctime>
# include <cstdlib>

class Bureaucrat;

class AForm {

	private:
		const std::string _name;
		bool _signed;
		const int _requiredGradeToSign;
		const int _requiredGradeToExecute;

	public:
		AForm();
		AForm(const std::string& name, int toSign, int toExec);
		AForm(const AForm& original);
		virtual ~AForm();
		AForm &operator=(const AForm& original);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		const std::string getName() const;
		bool getSigned() const;
		int getRequiredGradeToSign() const;
		int getRequiredGradeToExecute() const;
		void	beSigned(Bureaucrat& bureaucrat);
		void virtual execute(const Bureaucrat& executor) const = 0;

};

std::ostream &operator<<(std::ostream &os, const AForm& form);

#endif
