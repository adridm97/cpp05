/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:55:10 by adrian            #+#    #+#             */
/*   Updated: 2025/01/26 17:54:15 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() 
    : AForm("RobotomyRequestForm", 72, 45), _target("default:_target"){}
RobotomyRequestForm::RobotomyRequestForm(const std::string &target) 
    : AForm("RobotomyRequestForm", 72, 45), _target(target){}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other), _target(other._target){}
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    return(*this);
}
RobotomyRequestForm::~RobotomyRequestForm(){}
void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    if (!isSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException();
    std::cout << "* Drilling noises *" << std::endl;
    srand(time(NULL));
    if (rand() % 2)
        std::cout << _target << " has been robotomized successfully!" << std::endl;
    else
    {
        std::cout << "The robotomy on " << _target << " has failed!" << std::endl;
        throw std::runtime_error("Robotomy failed");
    }
}