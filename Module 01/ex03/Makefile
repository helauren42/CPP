# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: helauren <helauren@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/04 18:44:00 by helauren          #+#    #+#              #
#    Updated: 2024/02/04 22:24:09 by helauren         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = UNNECESSARYVIOLENCE

CXX = c++ -std=c++98

CXX_FLAGS = -Wall -Wextra -Werror

SRCS = main.cpp \
		HumanA.cpp \
		HumanB.cpp \
		Weapon.cpp \

OBJS = $(SRCS:.cpp=.o)

RM = rm -rf

$(NAME): $(OBJS)
	$(CXX) $(CXX_FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) -g $(CXX_FLAGS) -c $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean