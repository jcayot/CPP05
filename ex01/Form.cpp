//
// Created by jcayot on 8/17/24.
//

#include "Form.hpp"

Form::Form() : Form("Pointless form", 150, 150) {
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string& name, u_int gradeToSign, u_int gradeToExec) : name(name) {
	isSigned = false;
}

Form::Form(const Form& form) {

}

Form::~Form() {
}

Form& Form::operator=(const Form& form) {
}
