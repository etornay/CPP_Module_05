/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etornay- <etornay-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 14:39:49 by etornay-          #+#    #+#             */
/*   Updated: 2024/08/14 19:24:34 by etornay-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : name(), isSigned(false), signGrade(1), execGrade(1)
{
	std::cout << "Form: Default constructor called\n" << std::endl;
}

Form::Form(const std::string &name, int signGrade, int execGrade) : name(name), isSigned(false), signGrade(signGrade), execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
	std::cout << "Form: Attributes constructor called for " << name << std::endl << std::endl;
}

Form::Form(const Form &copy) : name(copy.name), isSigned(copy.isSigned), signGrade(copy.signGrade), execGrade(copy.execGrade)
{
	std::cout << "Form: Copy constructor called for " << copy.name << std::endl << std::endl;
}

Form &Form::operator = (const Form &other)
{
	if (this != &other)
	{
		this->isSigned = other.isSigned;
	}
	std::cout << "Form: Copy assignment operator called\n" << std::endl;
	return (*this);
}

Form::~Form(void)
{
	std::cout << "\nForm: Destructor called" << std::endl;
}

std::string Form::getName(void) const
{
	return (name);
}

bool Form::getIsSigned(void) const
{
	return (isSigned);
}

int Form::getSignGrade(void) const
{
	return (signGrade);
}

int Form::getExecGrade(void) const
{
	return (execGrade);
}

void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > signGrade)
		throw Form::GradeTooLowException();
	isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
		return ("Grade is too High!");
}

const char *Form::GradeTooLowException::what() const throw()
{
		return ("Grade is too Low!");
}

std::ostream &operator << (std::ostream &out, const Form &f)
{
	out << f.getName() << ", Form sign status " << (f.getIsSigned() ? "signed" : "not signed") << ". Required sign grade: " << f.getSignGrade() << ". Required execution grade: " << f.getExecGrade() << "." << std::endl;
	return (out);
}