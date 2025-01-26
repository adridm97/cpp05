/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:14:57 by adrian            #+#    #+#             */
/*   Updated: 2025/01/26 17:08:33 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    try
    {
        Bureaucrat john("John", 10);
        
        PresidentialPardonForm pardonForm("Alice");

        std::cout << pardonForm << std::endl;

        john.signForm(pardonForm);
        john.executeForm(pardonForm);
        Bureaucrat cris("Cris", 100);
        RobotomyRequestForm rForm("Adri");
        for(int i = 0; i < 90; i++)
            cris.incrementGrade();
        cris.signForm(rForm);
        cris.executeForm(rForm);
        std::cout << rForm << std::endl;
        cris.getGrade();
        ShrubberyCreationForm sForm("tree");
        cris.signForm(sForm);
        cris.executeForm(sForm);
        std::cout << sForm << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}