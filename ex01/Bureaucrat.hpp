/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etornay- <etornay-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 19:26:11 by etornay-          #+#    #+#             */
/*   Updated: 2024/08/14 19:09:40 by etornay-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <exception>
# include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
			const std::string	name;
			int					grade;

	public:
			Bureaucrat(void);
			Bureaucrat(std::string str, int grade);
			Bureaucrat(const Bureaucrat &copy);
			Bureaucrat &operator = (const Bureaucrat &other);
			~Bureaucrat(void);
			
			std::string getName(void) const;
			int getGrade(void) const;
			void setGrade(int grade);
			void increaseGrade(void);
			void decreaseGrade(void);
			void signForm(Form &form);
			
			class GradeTooHighException : public std::exception
			{
				const char *what() const throw();
			};
			class GradeTooLowException : public std::exception
			{
				const char *what() const throw();
			};
};
			std::ostream &operator << (std::ostream &out, const Bureaucrat &g);

#endif