NAME = a.out

CXX = c++

CXX_FLAGS = -g3 -Wall -Werror -Wextra

SRCS = main.cpp PmergeMe.cpp PmergeMeVector.cpp PmergeMeList.cpp 

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
