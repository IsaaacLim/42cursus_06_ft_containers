NAME		=	ft_container

SRCS		=	main.cpp

HDRS_DIR	=	./includes/
HDRS_LST	=	stack.hpp	vector.hpp VectorIterator.hpp
HDRS		=	$(addprefix $(HDRS_DIR), $(HDRS_LST))

INCLUDES	=	-I $(HDRS_DIR)

CXX			=	c++
CXXFLAGS	=	-std=c++11 -pedantic-errors -Wall -Wextra -Werror -g

all : $(NAME)

$(NAME) : $(SRCS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $^ -o $@
	@echo "!!!!!Change =std=c++11 & typedef<<>>!!!!!"

test_vector : Test_mine/vector.cpp 
	$(CXX) $(CXXFLAGS) $(INCLUDES) $^ -o $@ && ./$@
	@echo "!!!!!Change =std=c++11 & typedef<<>>!!!!!"

clean :
	@echo no object files to clean

fclean :
	rm -f $(NAME)
	rm -f test_vector

re : fclean all

.PHONY : all clean fclean re test_vector
