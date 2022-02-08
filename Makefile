NAME		=	ft_container

SRCS		=	main.cpp

HDRS_DIR	=	./includes/
HDRS_LST	=	map.hpp MyList.hpp stack.hpp	vector.hpp VectorIterator.hpp
HDRS		=	$(addprefix $(HDRS_DIR), $(HDRS_LST))

INCLUDES	=	-I $(HDRS_DIR)

CXX			=	clang++
CXXFLAGS	=	-std=c++98 -pedantic-errors -Wall -Wextra -Werror -g

all : $(NAME)

$(NAME) : $(SRCS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $^ -o $@
	@echo "!!!!!Change =std=c++11 & typedef<<>>!!!!!"

test_stack : TestScripts/stack.cpp TestScripts/utils.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $^ -o $@ && ./$@
	@echo "!!!!!Change =std=c++11 & typedef<<>>!!!!!"

test_vector : TestScripts/vector.cpp TestScripts/utils.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $^ -o $@ && ./$@
	@echo "!!!!!Change =std=c++11 & typedef<<>>!!!!!"

test_map : TestScripts/map.cpp TestScripts/utils.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $^ -o $@ && ./$@
	@echo "!!!!!Change =std=c++11 & typedef<<>>!!!!!"


clean :
	@echo no object files to clean

fclean :
	rm -f $(NAME)
	rm -f test_vector
	rm -f test_stack
	rm -f test_map

re : fclean all

.PHONY : all clean fclean re test_vector test_stack
