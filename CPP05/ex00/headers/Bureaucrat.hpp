/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:33:54 by andvieir          #+#    #+#             */
/*   Updated: 2023/11/06 09:33:54 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

# define MAX_GRADE 1
# define MIN_GRADE 150

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat();
		Bureaucrat(std::string const &name, int grade);
		Bureaucrat(const Bureaucrat& original);
		~Bureaucrat();
		Bureaucrat &operator=(const Bureaucrat& original);

		void				setGrade(int grade);

		const std::string 	getName() const;
		int					getGrade() const;
		void				incrementGrade(int grade);
		void				decrementGrade(int grade);

		class GradeTooHighException : public std::exception	{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

};

std::ostream &operator<<(std::ostream &out, const Bureaucrat& bureaucrat);

#endif
