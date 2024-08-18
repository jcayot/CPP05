//
// Created by jcayot on 8/17/24.
//

#include "Intern.hpp"


int	main() {
	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	delete rrf;
	return (0);
}
