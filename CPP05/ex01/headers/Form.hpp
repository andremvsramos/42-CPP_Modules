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

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

	private:
		const std::string _name;
		bool _signed;
		const int _requiredGradeToSign;
		const int _requiredGradeToExecute;

	public:
		Form();
		Form(const std::string& name, int toSign, int toExec);
		Form(const Form& original);
		~Form();
		Form &operator=(const Form& original);

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

};

std::ostream &operator<<(std::ostream &os, const Form& form);

#endif
