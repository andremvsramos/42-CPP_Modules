/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:48:31 by andvieir          #+#    #+#             */
/*   Updated: 2023/11/23 10:36:36 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Intern.hpp"

/* ===================== Orthodox Canonical Form ===================== */

Intern::Intern () {}

Intern::Intern (const Intern& original) {
    static_cast<void>(original);
    std::cout << "No such behaviour for copy" << std::endl;
}

Intern &Intern::operator=(const Intern& original) {
    std::cout << "No such behaviour for assigment" << std::endl;
    static_cast<void>(original);
    return (*this);
}

Intern::~Intern () {}

/* ===================== Exceptions ===================== */

const char *Intern::NoSuchForm::what() const throw() {
	return ("Intern Exception: Form does not exist");
}

/* ===================== Member functions ===================== */

AForm   *Intern::makeShrubbery(const std::string & target) {
    return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeRobotomy(const std::string & target) {
    return (new RobotomyRequestForm(target));
}

AForm  *Intern::makePresidential(const std::string & target) {
    return (new PresidentialPardonForm(target));
}

AForm   *Intern::makeForm(const std::string& name, const std::string& target) {
    std::string forms[3] = {
        "PresidentialPardonForm",
        "RobotomyRequestForm",
        "ShrubberyCreationForm"
    };

    AForm *(Intern::*createForm[3])(const std::string &) = {
        &Intern::makeShrubbery,
        &Intern::makeRobotomy,
        &Intern::makePresidential
    };

    for (size_t i = 0; i < 3; i++)
        if (name == forms[i])
           return ((this->*createForm[i])(target));
    throw NoSuchForm();
}

