/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etornay- <etornay-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 14:40:14 by etornay-          #+#    #+#             */
/*   Updated: 2024/08/14 19:13:59 by etornay-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
			const std::string	name;
			bool				isSigned;
			const int			signGrade;
			const int			execGrade;

	public:
			Form(void);
			Form(const std::string &name, int signGrade, int execGrade);
			Form(const Form &copy);
			Form &operator = (const Form &other);
			~Form(void);
			
			std::string getName(void) const;
			bool getIsSigned(void) const;
			int getSignGrade(void) const;
			int getExecGrade(void) const;

			void beSigned(const Bureaucrat &b);
			
			class GradeTooHighException : public std::exception
			{
				const char *what() const throw();
			};
			class GradeTooLowException : public std::exception
			{
				const char *what() const throw();
			};
};
			std::ostream &operator << (std::ostream &out, const Form &f);

#endif