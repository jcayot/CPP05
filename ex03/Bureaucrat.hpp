//
// Created by jcayot on 8/17/24.
//

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat {
	private:
		const std::string	name;
		u_int				grade;

	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, u_int grade);
		Bureaucrat(const Bureaucrat& bureaucrat);
		~Bureaucrat();

		Bureaucrat&	operator=(const Bureaucrat& bureaucrat);

		std::string	getName()	const;
		u_int		getGrade()	const;

		void		increaseGrade();
		void		decreaseGrade();
		void		signForm(AForm& form) const;
		void		executeForm(AForm& form) const;

	class GradeTooHighException : public std::exception {
		public:
			const char*	what() const noexcept override;
	};

	class GradeTooLowException : public std::exception {
		public:
			const char*	what() const noexcept override;
	};
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
