//
// Created by jules on 18/08/2024.
//

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : PresidentialPardonForm("") {
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("PresidentialPardonForm", 25, 5), target(target) {
	std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& presidentialPardonForm) {
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
	*this = presidentialPardonForm;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& presidentialPardonForm) {
	if (this != &presidentialPardonForm) {
		this->target = presidentialPardonForm.target;
		AForm::operator=(presidentialPardonForm);
	}
	return (*this);
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) {
	if (executor.getGrade() > this->getGradeToExec())
		throw GradeTooLowException();
	std::cout << target << "has been pardoned by Zaphod Beeblebrox." << std::endl;
}
