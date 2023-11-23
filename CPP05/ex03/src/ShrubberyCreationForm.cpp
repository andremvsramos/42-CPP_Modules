/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:26:14 by andvieir          #+#    #+#             */
/*   Updated: 2023/11/22 09:47:00 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ShrubberyCreationForm.hpp"

/* ===================== Orthodox Canonical Form ===================== */

ShrubberyCreationForm::ShrubberyCreationForm () :
    AForm("ShrubberyCreationForm", 145, 137),
    _outfile("default_shrubbery") {}

ShrubberyCreationForm::ShrubberyCreationForm (const ShrubberyCreationForm& original) :
    AForm(original), _outfile(original._outfile) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm& original) {
    if (this == &original)
        return (*this);
    AForm::operator=(original);
    _outfile = original._outfile;
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm () {}

/* ===================== Constructors ===================== */

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
    AForm("ShrubberyCreationForm", 145, 137),
    _outfile(target + "_shrubbery") {}

/* ===================== Getter functions ===================== */

std::string ShrubberyCreationForm::getOutfile() const {
    return (this->_outfile);
}

/* ===================== Member Functions ===================== */

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    if (executor.getGrade() > getRequiredGradeToExecute())
        throw GradeTooLowException();
    else if (!getSigned()) {
        std::cout << "Form not signed" << std::endl;
        return ;
    }
    else {
        std::ofstream out(getOutfile().c_str());
        out << "       _-_\n";
        out << "    /~~   ~~\\\n";
        out << " /~~         ~~\\\n";
        out << "{               }\n";
        out << " \\  _-     -_  /\n";
        out << "   ~  \\\\ //  ~\n";
        out << "_- -   | | _- _\n";
        out << "  _ -  | |   -_\n";
        out << "      // \\\\\n";
        out << "    /   \\  \\\n";
        out << "    /    /\\  \\\\";
        out << std::endl;
        out.close();
        }
}



