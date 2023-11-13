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

#include "../headers/Form.hpp"

/*===Constructors===*/

Form::Form() :
	_name("Default"), _signed(false),
	_requiredGradeToSign(MIN_GRADE), _requiredGradeToExecute(MIN_GRADE) {}

Form::~Form() {}

Form::Form(const std::string& name, int toSign, int toExec) :
	_name(name), _signed(false),
	_requiredGradeToSign(toSign), _requiredGradeToExecute(toExec) {
		if (this->_requiredGradeToSign < MAX_GRADE || this->_requiredGradeToExecute < MAX_GRADE)
			throw Form::GradeTooHighException();
		else if (this->_requiredGradeToSign > MIN_GRADE || this->_requiredGradeToExecute > MIN_GRADE)
			throw Form::GradeTooLowException();
	}

Form::Form(const Form& original) :
	_name(original._name), _signed(original._signed),
	_requiredGradeToSign(original._requiredGradeToSign),
	_requiredGradeToExecute(original._requiredGradeToExecute) {}


Form &Form::operator=(const Form& original) {
	if (this == &original)
		return (*this);
	this->_signed = original._signed;
	return (*this);
}

/*===Getters===*/

const std::string Form::getName() const {
	return (this->_name);
}

bool Form::getSigned() const {
	return (this->_signed);
}

int Form::getRequiredGradeToSign() const {
	return (this->_requiredGradeToSign);
}

int Form::getRequiredGradeToExecute() const {
	return (this->_requiredGradeToExecute);
}

/*===Exceptions===*/

const char *Form::GradeTooHighException::what() const throw() {
	return ("Form exception: Grade Too High");
}

const char *Form::GradeTooLowException::what() const throw() {
	return ("Form exception: Grade Too Low");
}


/*===Member Functions===*/

void Form::beSigned(Bureaucrat& bureaucrat) {
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
		throw Form::GradeTooLowException();
	}
}

/*===Overload Operators===*/

std::ostream &operator<<(std::ostream &os, const Form& form) {
	os << form.getName() << ", signed: " << form.getSigned()
		<< ", grade required to sign: " << form.getRequiredGradeToSign()
		<< ", grade required to execute: " << form.getRequiredGradeToExecute()
		<< std::endl;
	return (os);
}
