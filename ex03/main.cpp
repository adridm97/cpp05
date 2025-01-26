/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduenas- <aduenas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:14:57 by adrian            #+#    #+#             */
/*   Updated: 2025/01/26 19:11:16 by aduenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
    Intern someRandomIntern;
    AForm *form;
    Bureaucrat cris("Cris", 3);
    
    form = someRandomIntern.makeForm("robotomy request", "Bender");
    if (form)
    {   
        cris.signForm(*form);
        cris.executeForm(*form);
        delete form;
    }
    else
        std::cerr << "Form creation failed!" << std::endl;
    form = someRandomIntern.makeForm("shrubbery creation", "Garden");
    if (form)
        delete form;
    form = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
    if (form)
        delete form;
    form = someRandomIntern.makeForm("invalid form", "Nobody");
    if (form)
        delete form;
    return 0;
}