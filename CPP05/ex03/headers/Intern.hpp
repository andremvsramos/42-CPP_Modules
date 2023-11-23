/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:48:27 by andvieir          #+#    #+#             */
/*   Updated: 2023/11/23 09:55:15 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
# define INTERN_H

# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# pragma once

class AForm;

class Intern {
    public:
        Intern();
        Intern(const Intern& original);
        Intern&    operator=(const Intern& original);
        ~Intern();

        AForm   *makeForm(const std::string& name, const std::string& target);
        class NoSuchForm : public std::exception {
			public:
				virtual const char *what() const throw();
		};

        AForm   *makeShrubbery(const std::string & target);
        AForm     *makeRobotomy(const std::string & target);
        AForm  *makePresidential(const std::string & target);
};

#endif
