#include <iostream>

#define YELLOW "\033[0;33m"
#define PURPLE "\033[0;35m"
#define RESET "\033[0m"

void print_title(std::string str)
{
	std::cout << YELLOW;
	std::cout << "========================= " << str << " =========================" << std::endl;
	std::cout << RESET;
}

void print_subtitle(std::string str)
{
	std::cout << PURPLE;
	std::cout << "------------------------- " << str << " -------------------------" << std::endl;
	std::cout << RESET;
}
