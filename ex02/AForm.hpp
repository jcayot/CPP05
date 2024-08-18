//
// Created by jcayot on 8/17/24.
//

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		const std::string	name;
		bool				isSigned;
		const u_int			gradeToSign;
		const u_int			gradeToExec;

	public:
		AForm();
		AForm(const std::string& name, u_int gradeToSign, u_int gradeToExec);
		AForm(const AForm& form);
		virtual ~AForm();

		AForm&	operator=(const AForm& form);

		const std::string&		getName() const;
		const bool&				getIsSigned() const;
		const u_int&			getGradeToSign() const;
		const u_int&			getGradeToExec() const;

		void			beSigned(const Bureaucrat& bureaucrat);
		virtual void	execute(const Bureaucrat& executor) = 0;

	class GradeTooHighException : public std::exception {
		public:
			const char* what() const noexcept override;
	};

	class GradeTooLowException : public std::exception {
		public:
			const char* what() const noexcept override;
	};

	class FormNotSignedException : public std::exception {
		public:
			const char* what() const noexcept override;
	};
};

std::ostream&	operator<<(std::ostream& os, const AForm& form);

#endif
