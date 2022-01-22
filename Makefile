NAME		=	ft_container

SRCS		=	main.cpp

HDRS_DIR	=	./includes/
HDRS_LST	=	stack.hpp	vector.hpp VectorIterator.hpp
HDRS		=	$(addprefix $(HDRS_DIR), $(HDRS_LST))

INCLUDES	=	-I $(HDRS_DIR)

CXX			=	c++
CXXFLAGS	=	-std=c++98 -pedantic-errors -Wall -Wextra -Werror -g

all : $(NAME)

$(NAME) : $(SRCS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $^ -o $@

test_vector : Test_mine/vector.cpp 
	$(CXX) $(CXXFLAGS) $(INCLUDES) $^ -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
