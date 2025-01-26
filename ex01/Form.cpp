/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:30:01 by adrian            #+#    #+#             */
/*   Updated: 2025/01/20 18:41:13 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

const char *Form::GradeTooHighException::what() const throw()
{
    return("Form grade is too high.");
}
const char *Form::GradeTooLowException::what() const throw()
{
    return("Form grade is too low.");
}
Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
    : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _isSigned(false)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}
Form::Form(const Form &other) : _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute), _isSigned(other._isSigned){};
Form &Form::operator=(const Form &other)
{
    if (this != &other)
        _isSigned = other._isSigned;
    return(*this);
}
Form::~Form(){}
const std::string &Form::getName() const
{
    return(_name);
}
bool Form::isSigned() const
{
    return(_isSigned);
}
int Form::getGradeToSign() const
{
    return(_gradeToSign);
}
int Form::getGradeToExecute() const
{
    return(_gradeToExecute);
}
void Form::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
}

//Sobrecarga del operador <<
std::ostream &operator<<(std::ostream &os, const Form &f)
{
    if (f.isSigned() == 0)
        os << f.getName() << ", form grade to sign: " << f.getGradeToSign() << ", form grade to execute: " << f.getGradeToExecute() << ", status: not signed.";
    else
        os << f.getName() << ", form grade to sign: " << f.getGradeToSign() << ", form grade to execute: " << f.getGradeToExecute() << ", status: signed.";
    return (os);
}