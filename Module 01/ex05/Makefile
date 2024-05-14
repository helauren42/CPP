NAME = HARL_2.0

CXX = c++ -std=c++98

CXX_FLAGS = -Wall -Wextra -Werror

SRCS = main.cpp \
		Harl.cpp \

OBJS = $(SRCS:.cpp=.o)

RM = rm -rf

$(NAME): $(OBJS)
	$(CXX)$(CXX_FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) -g $(CXX_FLAGS) -c $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean
