/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etornay- <etornay-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 19:26:32 by etornay-          #+#    #+#             */
/*   Updated: 2024/08/14 19:19:22 by etornay-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    try
    {
        Bureaucrat b1("Elias", 145);
        Bureaucrat b2("Luna", 1);

        Form f1("Form1", 140, 130);
        Form f2("Form2", 2, 1);

        std::cout << b1 << std::endl;
        std::cout << b2 << std::endl;

        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;

        b1.signForm(f1);
        b2.signForm(f2);
        b1.signForm(f2);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return (0);
}