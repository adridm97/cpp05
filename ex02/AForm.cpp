/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:30:01 by adrian            #+#    #+#             */
/*   Updated: 2025/01/26 17:02:27 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

const char *AForm::GradeTooHighException::what() const throw()
{
    return("Form grade is too high");
}
const char *AForm::GradeTooLowException::what() const throw()
{
    return("Form grade is too low");
}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
    : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _isSigned(false)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}
AForm::AForm(const AForm &other) : _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute), _isSigned(other._isSigned){};
AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
        _isSigned = other._isSigned;
    return(*this);
}
AForm::~AForm(){}
const std::string &AForm::getName() const
{
    return(_name);
}
bool AForm::isSigned() const
{
    return(_isSigned);
}
int AForm::getGradeToSign() const
{
    return(_gradeToSign);
}
int AForm::getGradeToExecute() const
{
    return(_gradeToExecute);
}
void AForm::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
}

//Sobrecarga del operador <<
std::ostream &operator<<(std::ostream &os, const AForm &f)
{
    if (f.isSigned() == 0)
        os << f.getName() << ", form grade to sign: " << f.getGradeToSign() << ", form grade to execute: " << f.getGradeToExecute() << ", status: not signed.";
    else
        os << f.getName() << ", form grade to sign: " << f.getGradeToSign() << ", form grade to execute: " << f.getGradeToExecute() << ", status: signed.";
    return (os);
}