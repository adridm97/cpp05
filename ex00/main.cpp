/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:14:57 by adrian            #+#    #+#             */
/*   Updated: 2025/01/09 13:47:57 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b1("Adri", 1);
        std::cout << b1 << std::endl;
        b1.getGrade();
        std::cout << "After increment: " << b1 << std::endl;
        Bureaucrat b2("Cris", 150);
        b2.incrementGrade();
        std::cout << "After decrement: " << b2 << std:: endl;
    }
    catch(const Bureaucrat::GradeToHighException &e)
    {
        std::cerr << "High grade error attempting to increment: " << e.what() << std::endl;
    }
    catch(const Bureaucrat::GradeToLowException &e)
    {
        std::cerr << "Low grade error attempting to decrement: " << e.what() << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cerr << "Other error: " << e.what() << std::endl;
    }
    try
    {
        Bureaucrat b3("Pedro", 70);
        std::cout << b3.getName() << std::endl;
        std::cout << b3.getGrade() << std::endl;
    }
    catch(const Bureaucrat::GradeToHighException &e)
    {
        std::cerr << "High grade error attempting to increment: " << e.what() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}