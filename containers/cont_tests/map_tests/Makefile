SRCS			= main_map.cpp\
				  map_test.cpp\
				  ../showResult.cpp
OBJS			= $(SRCS:.cpp=.o)

CXX=clang++
CXXFLAGS		= -Wall -Wextra -Werror

NAME			= run_map

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re