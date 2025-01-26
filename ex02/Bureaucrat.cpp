/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:14:09 by adrian            #+#    #+#             */
/*   Updated: 2025/01/26 16:54:26 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const char *Bureaucrat::GradeToHighException::what() const throw()
{
    return ("Grade is to high! Maximum grade is 1.");
}
const char *Bureaucrat::GradeToLowException::what() const throw()
{
    return ("Grade is to low! Minimum grade is 150.");
}
Bureaucrat::Bureaucrat(){}
Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade)
{
    if (grade < 1)
        throw GradeToHighException();
    if (grade > 150)
        throw GradeToLowException();    
}
Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade){}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
        _grade = other._grade;
    return (*this);
}
Bureaucrat::~Bureaucrat(){}
//Getters
const std::string &Bureaucrat::getName() const
{
    return (_name);
}
int Bureaucrat::getGrade() const
{
    return (_grade);
}
//Metodos
void Bureaucrat::incrementGrade()
{
    if (_grade <= 1)
        throw GradeToHighException();
    else
        --_grade;
}
void Bureaucrat::decrementGrade()
{
    if (_grade >= 150)
        throw GradeToLowException();
    else
        ++_grade;
}

void Bureaucrat::signForm(AForm &f) const
{
    if (!f.isSigned())
    {
        try
        {
            f.beSigned(*this);
            std::cout << _name << " signed " << f.getName() << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << _name << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
        }
    }
    else
    {
        std::cout << _name << " couldn't sign " << f.getName() << " because it is already signed." << std::endl;
    }
}

void Bureaucrat::executeForm(const AForm &form) const
{
    try
    {
        form.execute(*this);
        std::cout << _name << " executed " << form.getName() << "." << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << _name << " couldn't execute " << form.getName() << " because " << e.what() << "." << std::endl;
    }
}

//Sobrecarga del operador <<
std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
    os << b.getName() << ", bureaucrat grade: " << b.getGrade();
    return (os);
}
