/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etornay- <etornay-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 19:26:32 by etornay-          #+#    #+#             */
/*   Updated: 2024/08/14 19:19:43 by etornay-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat *b1 = NULL;
	Bureaucrat *b2 = NULL;
	Bureaucrat *b3 = NULL;
	try
	{
		b1 = new Bureaucrat("Elias", 100);
		b2 = new Bureaucrat("Luna", 1);
		b3 = new Bureaucrat(*b1);
		
		std::cout << "b3 :" << *b3 <<std::endl;
		*b3 = *b2;
		std::cout << "b3 :" << *b3 <<std::endl;
		std::cout << "b1: " << *b1 << "\nb2: " << *b2 << std::endl;
		
		b1->decreaseGrade();
		b2->decreaseGrade();
		
		std::cout << "b1: " << *b1 << "\nb2: " << *b2 << std::endl;
		b1->increaseGrade();
		b2->increaseGrade();
		std::cout << "b1: " << *b1 << "\nb2: " << *b2 << std::endl;
		b2->increaseGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	delete b1;
	delete b2;
	delete b3;

	return (0);
}