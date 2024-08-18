//
// Created by jules on 18/08/2024.
//

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : ShrubberyCreationForm("") {
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", 145, 137), target(target) {
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& source) {
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
	*this = source;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& shrubberyCreationForm) {
	if (this != &shrubberyCreationForm) {
		this->target = shrubberyCreationForm.target;
		AForm::operator=(shrubberyCreationForm);
	}
	return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) {
	if (executor.getGrade() > this->getGradeToExec())
		throw GradeTooLowException();
	std::ofstream	outfile(target + "_shrubbery", std::ios::out);
	if (outfile.is_open()) {
		outfile << "    ^        ^    " << std::endl;
		outfile << "   ^^^      ^^^   " << std::endl;
		outfile << "  ^^^^^    ^^^^^  " << std::endl;
		outfile << " ^^^^^^^  ^^^^^^^ " << std::endl;
		outfile << "^^^^^^^^^^^^^^^^^^" << std::endl;
		outfile << "   |||      |||   " << std::endl;
		outfile << "   |||      |||   " << std::endl;
	} else
		std::cout << "ShrubberyCreationForm::execute could not open file" << std::endl;
}
