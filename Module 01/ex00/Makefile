NAME = BraiiiiiiinnnzzzZ

CXX = c++

CXX_FLAGS = -std=c++98 -Wall -Wextra -Werror

SRCS = main.cpp \
		newZombie.cpp \
		randomChump.cpp \
		Zombie.cpp \

OBJS = $(SRCS:.cpp=.o)

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXX_FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXX_FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
