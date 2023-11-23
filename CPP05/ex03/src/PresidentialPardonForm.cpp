/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:56:18 by andvieir          #+#    #+#             */
/*   Updated: 2023/11/22 09:46:18 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/PresidentialPardonForm.hpp"

/* ===================== Orthodox Canonical Form ===================== */

PresidentialPardonForm::PresidentialPardonForm () :
    AForm("PresidentialPardonForm", 25, 5), _target("Default Target") {}

PresidentialPardonForm::PresidentialPardonForm (const PresidentialPardonForm& original) :
    AForm(original), _target(original._target) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm& original) {
    if (this == &original)
        return (*this);
    this->_target = original._target;
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm () {}

/* ===================== Constructors ===================== */

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
    AForm("PresidentialPardonForm", 25, 5), _target(target) {}

/* ===================== Member Functions ===================== */

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
    if (executor.getGrade() > getRequiredGradeToExecute())
        throw GradeTooLowException();
    else if (!getSigned()) {
        std::cout << "Form not signed" << std::endl;
        return ;
    }
    else
        std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
