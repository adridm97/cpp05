# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adrian <adrian@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/08 18:12:18 by adrian            #+#    #+#              #
#    Updated: 2025/01/26 17:38:32 by adrian           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= Intern
CPP		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98 -fsanitize=address
SOURCES	= main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp Intern.cpp
HEADER	= Bureaucrat.hpp AForm.hpp PresidentialPardonForm.hpp RobotomyRequestForm.hpp ShrubberyCreationForm.hpp Intern.hpp
OBJS	= ${SOURCES:.cpp=.o}

%.o: %.cpp $(HEADER) Makefile
	$(CPP) $(CFLAGS) -c $< -o $@
all: $(NAME) Makefile
$(NAME): $(OBJS)
	$(CPP) $(CFLAGS) $(OBJS) -o $(NAME)
clean:
	rm -rf $(OBJS)
fclean: clean
	rm -rf $(NAME)
re: fclean all
.PHONY: all clean fclean re