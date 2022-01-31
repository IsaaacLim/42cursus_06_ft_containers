#include <iostream>

#if 1
#include <map>
namespace ft = std;
#else
#include "map.hpp"
#endif

void print_title(std::string str);
void print_subtitle(std::string str);

void map_int()
{
	print_title("Map");
}

int main()
{
	map_int();
}
