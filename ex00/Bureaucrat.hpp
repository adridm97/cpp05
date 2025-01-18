/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:14:21 by adrian            #+#    #+#             */
/*   Updated: 2025/01/09 11:54:14 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <stdexcept>
#include <iostream>

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
		//Geters
		const	std::string &getName() const;
		int	getGrade() const;
		//Metodos
		void	incrementGrade();
		void	decrementGrade();
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

#endif