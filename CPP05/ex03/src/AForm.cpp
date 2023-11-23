/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andvieir <andvieir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:43:07 by andvieir          #+#    #+#             */
/*   Updated: 2023/11/06 11:43:07 by andvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/AForm.hpp"

/* ===================== Orthodox Canonical Form ===================== */

AForm::AForm() :
	_name("Default"), _signed(false),
	_requiredGradeToSign(MIN_GRADE), _requiredGradeToExecute(MIN_GRADE) {}

AForm::AForm(const AForm& original) :
	_name(original.getName()), _signed(original.getSigned()),
	_requiredGradeToSign(original.getRequiredGradeToSign()),
	_requiredGradeToExecute(original.getRequiredGradeToExecute()) {}

AForm &AForm::operator=(const AForm& original) {
	if (this == &original)
		return (*this);
	this->_signed = original._signed;
	return (*this);
}

AForm::~AForm() {}

/* ===================== Constructors ===================== */

AForm::AForm(const std::string& name, int toSign, int toExec) :
	_name(name), _signed(false),
	_requiredGradeToSign(toSign), _requiredGradeToExecute(toExec) {
		if (this->_requiredGradeToSign < MAX_GRADE || this->_requiredGradeToExecute < MAX_GRADE)
			throw AForm::GradeTooHighException();
		else if (this->_requiredGradeToSign > MIN_GRADE || this->_requiredGradeToExecute > MIN_GRADE)
			throw AForm::GradeTooLowException();
	}

/* ===================== Getter functions ===================== */

const std::string AForm::getName() const {
	return (this->_name);
}

bool AForm::getSigned() const {
	return (this->_signed);
}

int AForm::getRequiredGradeToSign() const {
	return (this->_requiredGradeToSign);
}

int AForm::getRequiredGradeToExecute() const {
	return (this->_requiredGradeToExecute);
}

/* ===================== Exceptions ===================== */

const char *AForm::GradeTooHighException::what() const throw() {
	return ("Form exception: Grade Too High");
}

const char *AForm::GradeTooLowException::what() const throw() {
	return ("Form exception: Grade Too Low");
}

/* ===================== Overloaders ===================== */

std::ostream &operator<<(std::ostream &os, const AForm& form) {
	os << form.getName() << ", signed: " << form.getSigned()
		<< ", grade required to sign: " << form.getRequiredGradeToSign()
		<< ", grade required to execute: " << form.getRequiredGradeToExecute()
		<< std::endl;
	return (os);
}

/* ===================== Member Functions ===================== */

void AForm::beSigned(Bureaucrat& bureaucrat) {
	if (this->_signed) {
		std::cout << "Form is already signed" << std::endl;
		return ;
	}
	if (bureaucrat.getGrade() <= this->getRequiredGradeToSign()) {
		this->_signed = true;
		bureaucrat.signForm(*this);
	}
	else {
		std::cout << bureaucrat.getName() << " cannot sign "
			<< this->getName() << std::endl;
		throw AForm::GradeTooLowException();
	}
}

