NAME = a.out

CPP = c++ -std=c++98

CPP_FLAGS = -Wall -Werror -Wextra

SRCS = main.cpp \
		ClapTrap.cpp \

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
