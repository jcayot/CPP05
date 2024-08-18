//
// Created by jules on 18/08/2024.
//

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include "AForm.hpp"


class PresidentialPardonForm : public AForm {
	private:
		std::string target;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& presidentialPardonForm);
		~PresidentialPardonForm();

		PresidentialPardonForm&	operator=(const PresidentialPardonForm& presidentialPardonForm);

		void	execute(const Bureaucrat& executor) override;
};



#endif //PRESIDENTIALPARDONFORM_HPP
