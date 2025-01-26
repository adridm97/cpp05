/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:08:01 by adrian            #+#    #+#             */
/*   Updated: 2025/01/20 19:32:58 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <stdexcept>
#include <iostream>
class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		const int 			_gradeToSign;
		const int			_gradeToExecute;
		bool				_isSigned;
	public:
		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class FormNotSignedException : public std::exception
		{
			public:
				const char *what() const throw()
				{
					return "Form is not signed!";
				}
		};
		AForm();
		AForm(const std::string &name, int gradeToSign, int gradeToExecute);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		virtual ~AForm();
		
		const std::string &getName() const;
		bool isSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		virtual void beSigned(const Bureaucrat &b);
		virtual void execute(const Bureaucrat &executor) const = 0;
};
std::ostream &operator<<(std::ostream &os, const AForm &f);

#endif