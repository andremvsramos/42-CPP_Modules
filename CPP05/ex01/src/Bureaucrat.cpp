/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:11:09 by andvieir          #+#    #+#             */
/*   Updated: 2023/11/06 13:11:09 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default") {
	this->setGrade(MIN_GRADE);
}

Bureaucrat::Bureaucrat(std::string const& name, int grade) : _name(name) {
	if (grade < MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
	else this->setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& original) : _name(original.getName()) {
	this->setGrade(original.getGrade());
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& original) {
	if (this == &original)
		return (*this);
	if (this->getName() != original.getName())
		std::cout << "Only grade will be copied" << std::endl;
	this->setGrade(original.getGrade());
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

void	Bureaucrat::setGrade(int grade) {
	if (grade < MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
}

const std::string Bureaucrat::getName() const {
	return (this->_name);
}

int Bureaucrat::getGrade() const {
	return (this->_grade);
}

void Bureaucrat::incrementGrade(int grade) {
	this->setGrade(getGrade() - grade);
}

void Bureaucrat::decrementGrade(int grade) {
	this->setGrade(getGrade() + grade);
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat& bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return (os);
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Bureaucrat exception: Grade Too High");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Bureaucrat exception: Grade Too Low");
}

void Bureaucrat::signForm(Form& form) {
	if (form.getSigned())
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	else {
		if (this->getGrade() <= form.getRequiredGradeToSign())
			form.beSigned(*this);
		else {
			std::cout << this->getName() << " cannot sign " << std::endl;
			throw Form::GradeTooLowException();
		}
	}
}
