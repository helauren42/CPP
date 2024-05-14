# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: helauren <helauren@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/08 00:13:03 by helauren          #+#    #+#              #
#    Updated: 2024/02/08 18:39:21 by helauren         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = out

CPP = c++ -std=c++98

CPP_FLAGS = -Wall -Werror -Wextra #-no-pie

RM = rm -rf

SRCS = main.cpp \
		Fixed.cpp \

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPP_FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CPP) -g $(CPP_FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean