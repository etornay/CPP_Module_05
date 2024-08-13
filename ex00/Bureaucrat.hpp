/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etornay- <etornay-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 19:26:11 by etornay-          #+#    #+#             */
/*   Updated: 2024/08/13 18:56:05 by etornay-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <exception>

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
			
			class GradeTooHighException : public std::exception
			{
				const char *what() const throw();
			};
			class GradeTooLowException : public std::exception
			{
				const char *what() const throw();
			};
};
#endif
			std::ostream &operator << (std::ostream &out, const Bureaucrat &g);