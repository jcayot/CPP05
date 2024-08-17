//
// Created by jcayot on 8/17/24.
//

#include "Bureaucrat.hpp"

int	main() {
	Bureaucrat b1("Idiot", 150), b2("Stupid", 50), b3("Retard", 1), b4;

	std::cout << b1 << b2 << b3 << b4;

	try {
		b1.increaseGrade();
		b2.increaseGrade();
		b3.increaseGrade();
	} catch (std::exception &exception) {
		std::cout << exception.what() << std::endl;
	}

	std::cout << b1 << b2 << b3 << b4;

	try {
		b1.decreaseGrade();
		b2.decreaseGrade();
		b3.decreaseGrade();
		b1.decreaseGrade();
	} catch (std::exception &exception) {
		std::cout << exception.what() << std::endl;
	}
	std::cout << b1 << b2 << b3 << b4;

	return (0);
}
