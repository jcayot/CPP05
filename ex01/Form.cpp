//
// Created by jcayot on 8/17/24.
//

#include "Form.hpp"

Form::Form() : Form("Pointless form", 150, 150) {
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string& name, u_int gradeToSign, u_int gradeToExec) : name(name), gradeToSign(gradeToSign), gradeToExec(gradeToExec) {
	std::cout << "Form constructor called" << std::endl;
	if (gradeToSign > 150 || gradeToExec > 150)
		throw GradeTooLowException();
	if (gradeToSign < 1 || gradeToExec < 1)
		throw GradeTooHighException();
	isSigned = false;
}

Form::Form(const Form& form) : Form(form.name, form.gradeToSign, form.gradeToExec) {
	std::cout << "Form copy constructor called" << std::endl;
	*this = form;
}

Form::~Form() {
	std::cout << "Form destructor called" << std::endl;
}

Form& Form::operator=(const Form& form) {
	if (this != &form) {
		this->isSigned = form.isSigned;
	}
	return (*this);
}

const std::string& Form::getName() const {
	return (this->name);
}

const bool& Form::getIsSigned() const {
	return (this->isSigned);
}

const u_int& Form::getGradeToSign() const {
	return (this->gradeToSign);
}

const u_int& Form::getGradeToExec() const {
	return (this->gradeToExec);
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
	if (this->isSigned)
		throw AlreadySignedException();
	if (bureaucrat.getGrade() > this->gradeToSign)
		throw GradeTooLowException();
	this->isSigned = true;
}

const char* Form::GradeTooHighException::what() const noexcept {
	return ("Error : Grade too high");
}

const char* Form::GradeTooLowException::what() const noexcept {
	return ("Error : Grade too low");
}

const char* Form::AlreadySignedException::what() const noexcept {
	return ("Error : Form already signed");
}

std::ostream&	operator<<(std::ostream& os, const Form& form) {
	os << form.getName() << ", isSigned: " << (form.getIsSigned() ? "true" : "false") <<
		", gradeToSign: " << form.getGradeToSign() << ", gradeToExec: " << form.getGradeToExec();
	return (os);
}
