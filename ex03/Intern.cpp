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

Intern& Intern::operator=(const Intern& intern) = default;

AForm* Intern::makeForm(const std::string& formName, const std::string& formTarget) {
	std::string	formNames[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
	AForm* (Intern::*formCreationFunctions[3])(const std::string&) =
		{&Intern::makePresidentialPardon, &Intern::makeShrubberyCreation, &Intern::makeRobotomyRequest};
	for (int i = 0; i < 3; i++) {
		if (formName == formNames[i])
			return (this->*formCreationFunctions[i])(formTarget);
	}
	return (nullptr);
}

AForm* Intern::makePresidentialPardon(const std::string& formTarget) {
	return (new PresidentialPardonForm(formTarget));
}

AForm* Intern::makeShrubberyCreation(const std::string& formTarget) {
	return (new ShrubberyCreationForm(formTarget));
}

AForm* Intern::makeRobotomyRequest(const std::string& formTarget) {
	return (new RobotomyRequestForm(formTarget));
}
