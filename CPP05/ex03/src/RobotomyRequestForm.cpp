/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:57:29 by andvieir          #+#    #+#             */
/*   Updated: 2023/11/22 09:46:32 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/RobotomyRequestForm.hpp"

/* ===================== Orthodox Canonical Form ===================== */

RobotomyRequestForm::RobotomyRequestForm () :
    AForm("RobotomyRequestForm", 72, 45), _target("Default Target") {}

RobotomyRequestForm::RobotomyRequestForm (const RobotomyRequestForm& original) :
    AForm(original), _target(original._target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm& original) {
    if (this == &original)
        return (*this);
    _target = original._target;
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm () {}

/* ===================== Constructors ===================== */

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
    AForm("RobotomyRequestForm", 72, 45), _target(target) {}

/* ===================== Member Functions ===================== */

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
    if (executor.getGrade() > getRequiredGradeToExecute())
        throw GradeTooLowException();
    else if (!getSigned()) {
        std::cout << "Form not signed" << std::endl;
        return ;
    }
    else {
        std::cout << "* Some drilling noises *" << std::endl;
        if (std::rand() % 2 == 0)
            std::cout << _target << " has been robotomized successfully" << std::endl;
        else
            std::cout << _target << " robotomization failed" << std::endl;
    }
}
