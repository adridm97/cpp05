/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduenas- <aduenas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:14:21 by adrian            #+#    #+#             */
/*   Updated: 2025/01/26 19:00:34 by aduenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <stdexcept>
#include <iostream>
#include "Form.hpp"

class Bureaucrat
{
	private:
		const std::string	_name;
		int	_grade;
	public:
		class GradeToHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class GradeToLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};
    	Bureaucrat();
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
    	~Bureaucrat();
		//Getters
		const	std::string &getName() const;
		int	getGrade() const;
		//Methods
		void	incrementGrade();
		void	decrementGrade();
		void	signForm(Form &form) const;
};
std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

#endif