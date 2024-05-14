NAME = convert

CXX = c++ -std=c++98

CXX_FLAGS = -g -Wall -Werror -Wextra

SRCS = ./src/main.cpp \
		./src/ScalarTypes.cpp \

OBJS = $(SRCS:.cpp=.o)

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