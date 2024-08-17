//
// Created by jcayot on 8/17/24.
//

#include "Bureaucrat.hpp"

int	main() {
	Bureaucrat b1("Idiot", 150), b2("Stupid", 50), b3("Retard", 1), b4;
	Form f1("Useless", 150, 150), f2("Pointless", 50, 50),
		f3("Meaningless", 1, 1), f4;

	b1.signForm(f2);
	b2.signForm(f3);
	b2.signForm(f2);
	b1.signForm(f1);
	b4.signForm(f4);
	b3.decreaseGrade();
	b3.signForm(f3);
	b3.increaseGrade();
	b3.signForm(f3);
	return (0);
}
