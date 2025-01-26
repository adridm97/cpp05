/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduenas- <aduenas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:14:57 by adrian            #+#    #+#             */
/*   Updated: 2025/01/26 19:02:06 by aduenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b1("Adri", 1);
        std::cout << b1 << std::endl;
        Bureaucrat b2("Cris", 150);
        std::cout << b2 << std::endl;
        b2.incrementGrade();
        std::cout << "After increment: " << b2 << std:: endl;
        Form f1("Formulario 1", 10, 3);
        f1.isSigned();
        std::cout << f1 << std::endl;
        std::cout << "Cris is going to sign the form." << std::endl;
        b2.signForm(f1);
        std::cout << "Adri is going to sign the form." << std::endl;
        b1.signForm(f1);
        std::cout << f1 << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}