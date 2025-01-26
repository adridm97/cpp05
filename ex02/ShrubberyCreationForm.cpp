/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduenas- <aduenas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:42:47 by adrian            #+#    #+#             */
/*   Updated: 2025/01/26 19:05:01 by aduenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137), _target("default_target"){}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): AForm("ShrubberyCreationForm", 145, 137), _target(target){}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), _target(other._target){}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}
ShrubberyCreationForm::~ShrubberyCreationForm(){}
void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    if (!isSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException();
    std::ofstream file((_target + "_shrubbery").c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return ;
    }
    file << "         *\n";
    file << "        ***\n";
    file << "       *****\n";
    file << "      *******\n";
    file << "     *********\n";
    file << "    ***********\n";
    file << "   *************\n";
    file << "        |||\n";
    file << "        |||\n";
    file << "        |||\n";
    file.close();
}