//
// Created by jules on 18/08/2024.
//

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : RobotomyRequestForm("") {
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", 72, 45) , target(target) {
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& robotomyRequestForm) {
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
	*this = robotomyRequestForm;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& robotomyRequestForm) {
	if (this != &robotomyRequestForm) {
		this->target = robotomyRequestForm.target;
		AForm::operator=(robotomyRequestForm);
	}
	return (*this);
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) {
	if (executor.getGrade() > this->getGradeToExec())
		throw GradeTooLowException();
	std::cout << "some drilling noises" << std::endl;
	if (rand() % 2 == 0) {
		std::cout << target << " has been robotomized successfully!" << std::endl;
	} else {
		std::cout << target << " robotomization has failed!" << std::endl;
	}
}
