# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: helauren <helauren@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/07 23:34:27 by helauren          #+#    #+#              #
#    Updated: 2024/02/07 23:34:28 by helauren         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = out

CPP = c++ -std=c++98

CPP_FLAGS = -Wall -Werror -Wextra

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