//
// Created by jcayot on 8/17/24.
//

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : Bureaucrat("", 150) {
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, u_int grade) : name(name) {
	std::cout << "Bureaucrat constructor called" << std::endl;
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& bureaucrat) : Bureaucrat(this->name, 150) {
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = bureaucrat;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& bureaucrat) {
	if (this != &bureaucrat)
		this->grade = bureaucrat.grade;
	return (*this);
}

void	Bureaucrat::increaseGrade() {
	if (grade < 2)
		throw GradeTooHighException();
	grade--;

}

void	Bureaucrat::decreaseGrade() {
	if (grade > 149)
		throw GradeTooLowException();
	grade++;
}

void Bureaucrat::signForm(AForm& form) const {
	if (!form.getIsSigned()) {
		try {
			form.beSigned(*this);
			std::cout << this->name << " signed " << form.getName() << std::endl;
		} catch (AForm::GradeTooLowException &e) {
			std::cout << this->name << " couldn’t sign " << form.getName() << " because of " << e.what() << std::endl;
		}
	} else
		std::cout << this->name << " couldn’t sign " << form.getName() << " because of " << "already signed" << std::endl;
}

std::string	Bureaucrat::getName() const {
	return (name);
}

u_int	Bureaucrat::getGrade() const {
	return (grade);
}

void	Bureaucrat::executeForm(AForm& form) const {
	try {
		form.execute(*this);
		std::cout << this->name << " executed " << form.getName() << std::endl;
	} catch (AForm::FormNotSignedException &e) {
		std::cout << this->name << " couldn’t execute " << form.getName() << " because of " << e.what() << std::endl;
	} catch (AForm::GradeTooLowException &e) {
		std::cout << this->name << " couldn’t execute " << form.getName() << " because of " << e.what() << std::endl;
	}
}

const char*	Bureaucrat::GradeTooHighException::what() const noexcept {
	return ("Error : Grade too high");
}

const char*	Bureaucrat::GradeTooLowException::what() const noexcept {
	return ("Error : Grade too low");
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return (os);
}
