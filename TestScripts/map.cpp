#include <iostream>
#include <string>

#if 1
#include <map>
namespace ft = std;
#else
#include "map.hpp"
#endif

void print_title(std::string str);
void print_subtitle(std::string str);

template <typename T, typename U>
void print_map(ft::map<T, U> map, std::string str)
{
	typename ft::map<T, U>::iterator it;

	if (!str.empty())
		std::cout << str;
	for (it = map.begin(); it != map.end(); it++)
		std::cout << "\t" << it->first << "\t" << it->second << '\n';
	std::cout << std::endl;
}

void map_int()
{
	print_title("Map");

	ft::map<int, int> map;

	map.insert(std::pair<int, int>(1, 40));
	map.insert(std::pair<int, int>(2, 30));
	map.insert(std::pair<int, int>(3, 60));
	map[4] = -1; // 4 is not the index, it's the key
	map[-1] = -2;
	map['a'] = -3;
	map[2] = -4;
	print_map(map, "Initial map:\n");
}

int main()
{
	map_int();
}
