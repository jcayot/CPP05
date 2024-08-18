//
// Created by jules on 18/08/2024.
//

#include "Intern.hpp"

Intern::Intern() {
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern& intern) {
	std::cout << "Intern copy constructor called" << std::endl;
	*this = intern;
}

Intern::~Intern() {
	std::cout << "Intern destructor called" << std::endl;
}

Intern& Intern::operator=(const Intern& intern) {
	return (*this);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& formTarget) {
	switch (formName) {
		case "PresidentialPardonForm" :
			return (new PresidentialPardonForm(formTarget));
		case "RobotomyRequestForm" :
			return (new RobotomyRequestForm(formTarget));
		case "ShrubberyCreationForm" :
			return (new ShrubberyCreationForm(formTarget));
		default:
			std::cout << formName << "couldn't be find by unknown intern" << std::endl;
	}
	return (nullptr);
}
