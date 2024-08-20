NAME = btc

CXX = c++ -std=c++98

CXX_FLAGS = -g3 -Wall -Werror -Wextra

SRCS = main.cpp \
		BitcoinExchange.cpp

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