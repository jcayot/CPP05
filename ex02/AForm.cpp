//
// Created by jcayot on 8/17/24.
//

#include "AForm.hpp"

AForm::AForm() : AForm("Pointless form", 150, 150) {
	std::cout << "Form default constructor called" << std::endl;
}

AForm::AForm(const std::string& name, u_int gradeToSign, u_int gradeToExec) : name(name), gradeToSign(gradeToSign), gradeToExec(gradeToExec) {
	std::cout << "Form constructor called" << std::endl;
	if (gradeToSign > 150 || gradeToExec > 150)
		throw GradeTooLowException();
	if (gradeToSign < 1 || gradeToExec < 1)
		throw GradeTooHighException();
	isSigned = false;
}

AForm::AForm(const AForm& form) : AForm(form.name, form.gradeToSign, form.gradeToExec) {
	std::cout << "Form copy constructor called" << std::endl;
	*this = form;
}

AForm::~AForm() {
	std::cout << "Form destructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& form) {
	if (this != &form) {
		this->isSigned = form.isSigned;
	}
	return (*this);
}

const std::string& AForm::getName() const {
	return (this->name);
}

const bool& AForm::getIsSigned() const {
	return (this->isSigned);
}

const u_int& AForm::getGradeToSign() const {
	return (this->gradeToSign);
}

const u_int& AForm::getGradeToExec() const {
	return (this->gradeToExec);
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > this->gradeToSign)
		throw GradeTooLowException();
	this->isSigned = true;
}

const char* AForm::GradeTooHighException::what() const noexcept {
	return ("Error : Grade too high");
}

const char* AForm::GradeTooLowException::what() const noexcept {
	return ("Error : Grade too low");
}

const char* AForm::FormNotSignedException::what() const noexcept {
	return ("Error : Form is not signed");
}

std::ostream&	operator<<(std::ostream& os, const AForm& form) {
	os << form.getName() << ", isSigned: " << (form.getIsSigned() ? "true" : "false") <<
		", gradeToSign: " << form.getGradeToSign() << ", gradeToExec: " << form.getGradeToExec();
	return (os);
}
