/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etornay- <etornay-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 19:26:13 by etornay-          #+#    #+#             */
/*   Updated: 2024/08/13 19:10:11 by etornay-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : name(), grade(150)
{
	std::cout << "Bureaucrat: Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string str, int grade) : name(str)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
	std::cout << "Bureaucrat: Attributes constructor called for " << name << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : name(copy.name), grade(copy.grade)
{
	std::cout << "Bureaucrat: Copy constructor called for " << name << std::endl;
}

Bureaucrat &Bureaucrat::operator = (const Bureaucrat &other)
{
	if (this != &other)
	{
		this->grade = other.grade;
		if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
	}
	std::cout << "Bureaucrat: Copy assignment operator called" << std::endl;
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat: Destructor called" << std::endl;
}

std::string Bureaucrat::getName(void) const
{
	return (name);
}

int Bureaucrat::getGrade(void) const
{
	return (grade);
}

void Bureaucrat::setGrade(int grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
	std::cout << "Bureaucrat: grade set to " << this->grade << std::endl;
}

void Bureaucrat::increaseGrade(void)
{
	if (this->grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	grade--;
}

void Bureaucrat::decreaseGrade(void)
{
	if (this->grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
		return ("Grade is too High!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
		return ("Grade is too Low!");
}

std::ostream &operator << (std::ostream &out, const Bureaucrat &g)
{
	out << g.getName() << ", Bureaucrat grade " << g.getGrade() << "." << std::endl;
	return (out);
}