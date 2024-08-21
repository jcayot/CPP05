//
// Created by jcayot on 8/17/24.
//

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string	name;
		bool				isSigned;
		const u_int			gradeToSign;
		const u_int			gradeToExec;

	public:
		Form();
		Form(const std::string& name, u_int gradeToSign, u_int gradeToExec);
		Form(const Form& form);
		~Form();

		Form&	operator=(const Form& form);

		const std::string&		getName() const;
		const bool&				getIsSigned() const;
		const u_int&			getGradeToSign() const;
		const u_int&			getGradeToExec() const;

		void	beSigned(const Bureaucrat& bureaucrat);

	class GradeTooHighException : public std::exception {
		public:
			const char* what() const noexcept override;
	};

	class GradeTooLowException : public std::exception {
		public:
			const char* what() const noexcept override;
	};

	class AlreadySignedException : public std::exception {
		public:
			const char*	what() const noexcept override;
	};
};

std::ostream&	operator<<(std::ostream& os, const Form& form);

#endif
