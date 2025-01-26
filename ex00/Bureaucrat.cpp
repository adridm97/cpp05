/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduenas- <aduenas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:14:09 by adrian            #+#    #+#             */
/*   Updated: 2025/01/26 18:58:42 by aduenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const char *Bureaucrat::GradeToHighException::what() const throw()
{
    return ("Grade is too high! Maximum grade is 1.");
}
const char *Bureaucrat::GradeToLowException::what() const throw()
{
    return ("Grade is too low! Minimum grade is 150.");
}
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
//Sobrecarga del operador <<
std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
    os << b.getName() << ", bureaucrat grade: " << b.getGrade();
    return (os);
}