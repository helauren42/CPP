# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: helauren <helauren@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/11 23:04:18 by helauren          #+#    #+#              #
#    Updated: 2024/02/12 00:29:39 by helauren         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out

CPP = c++ -std=c++98

CPP_FLAGS = -Wall -Werror -Wextra

SRCS = Cat.cpp \
		Dog.cpp \
		Animal.cpp \
		WrongAnimals.cpp \
		WrongCat.cpp \
		main.cpp \

OBJS = $(SRCS:.cpp=.o)

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
		$(CPP) $(CPP_FLAGS) $(OBJS) -o $(NAME)

%.o:%.cpp
		$(CPP) $(CPP_FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
