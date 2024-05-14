# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: helauren <helauren@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/20 01:54:48 by helauren          #+#    #+#              #
#    Updated: 2024/02/22 22:13:33 by helauren         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out

CXX = c++ -std=c++98

CXX_FLAGS = -Wall -Werror -Wextra

SRCS = ./src/main.cpp \
		./src/Bureaucrat.cpp \
		./src/AForm.cpp \
		./src/ShrubberyCreationForm.cpp \
		./src/RobotomyRequestForm.cpp \
		./src/PresidentialPardonForm.cpp \

OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp
	$(CXX) -g $(CXX_FLAGS) -c $< -o $@

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXX_FLAGS) $(OBJS) -o $(NAME)
	
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
