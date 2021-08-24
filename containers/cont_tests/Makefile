SRCS			= main_vector.cpp\
				  vector_tests/vector_test.cpp\
				  test.cpp
				  
OBJS			= $(SRCS:.cpp=.o)

CXX=clang++
CXXFLAGS		= -Wall -Wextra -Werror

NAME			= ex02

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re