NAME		=	ft_container

SRCS		=	main.cpp
OBJS		=	$(SRCS:.cpp=.o)

HDRS_DIR	=	./includes/
HDRS_LST	=	Stack.hpp	Vector.hpp
HDRS		=	$(addprefix $(HDRS_DIR), $(HDRS_LST))

INCLUDES	=	-I $(HDRS_DIR)

CXX			=	c++
CXXFLAGS	=	-std=c++98 -pedantic-errors -Wall -Wextra -Werror -g

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o : %.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c $(INCLUDES) $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
