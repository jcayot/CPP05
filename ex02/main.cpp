//
// Created by jcayot on 8/17/24.
//

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main() {
	Bureaucrat b1("Idiot", 150), b2("Stupid", 50), b3("Retard", 1), b4;
	PresidentialPardonForm	p = PresidentialPardonForm("president itself");
	RobotomyRequestForm		r = RobotomyRequestForm("bad roobot");
	ShrubberyCreationForm	s = ShrubberyCreationForm("forest");

	b1.executeForm(p);
	b3.signForm(p);
	b2.executeForm(p);
	b1.executeForm(p);

	b2.signForm(r);
	b2.executeForm(r);
	b1.executeForm(r);

	b2.signForm(s);
	b2.executeForm(s);
	return (0);
}
