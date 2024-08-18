//
// Created by jules on 18/08/2024.
//

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
	public:
		Intern();
		Intern(const Intern &intern);
		~Intern();

		Intern &operator=(const Intern &intern);

		AForm*	makeForm(const std::string& formName, const std::string& formTarget);
};

#endif
