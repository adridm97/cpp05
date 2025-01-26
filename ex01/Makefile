# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adrian <adrian@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/08 18:12:18 by adrian            #+#    #+#              #
#    Updated: 2025/01/18 16:47:07 by adrian           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= Bureaucrat
CPP		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98 -fsanitize=address
SOURCES	= main.cpp Bureaucrat.cpp Form.cpp
HEADER	= Bureaucrat.hpp Form.hpp
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