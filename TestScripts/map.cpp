#include <iostream>
#include <string>
#include <iomanip>

#if 1
#include <map>
namespace ft = std;
#else
#include "map.hpp"
#endif

void print_title(std::string str);
void print_subtitle(std::string str);

template <typename T, typename U, typename V>
void print_map(ft::map<T, U, V> map, std::string str)
{
	typename ft::map<T, U, V>::iterator it;

	if (!str.empty())
		std::cout << str;
	for (it = map.begin(); it != map.end(); it++)
		std::cout << std::setw(5) << it->first << " | " << it->second << '\n';
	std::cout << std::endl;
}

template <typename It>
void printInsertionStatus(It it, bool success, std::string str) // method from cppreference
{
	if (!str.empty())
		std::cout << str;
	std::cout << "Insertion of " << it->first << (success ? " succeeded\n" : " failed\n");
}

template <typename T, typename U> // not used
ft::map<T, U> comparator(ft::map<T, U> map1, ft::map<T, U> map2)
{
	if (map1 < map2)
		return (map1);
	else
		return (map2);
}

void map_int()
{
	print_title("Map");

	// Member Functions
	{
		print_subtitle("Member Functions");

		ft::map<int, int> map; // (1)

		map.insert(std::pair<int, int>(1, 40));
		map.insert(std::pair<int, int>(2, 30));
		map[-1] = -2; // -1 is not the index, it's the key
		map['a'] = -3;
		map[2] = -4;

		const std::allocator<std::pair<const int, int> > alloc;
		// ft::map<int, int> map2(map.begin(), map.end(), alloc); //(2, c++14)
		ft::map<int, int> map2(map.begin(), map.end()); //(2)
		ft::map<int, int> map3(map);						   // (3)
		ft::map<int, int, std::less<int> > map4 = map;		   // (3)
		ft::map<char, int, std::greater<char> > map5;		   // (1)
		// ft::map<int, int> map6(std::greater<int>); // can compile but can't modify
		// ft::map<int, int> map7(map.begin(), map.end(), comparator, alloc); // doesn't work

		map5['a'] = 1;
		map5['B'] = 10;
		map5['b'] = -20;
		map5['A'] = 100;

		print_map(map, "map:\n");
		print_map(map2, "map2:\n");
		print_map(map3, "map3:\n");
		print_map(map4, "map4:\n");
		print_map(map5, "map5:\n");

		std::allocator<std::pair<const int, int> > Allocator;
		std::pair<const int, int> *ptr = NULL;
		Allocator = map.get_allocator();
		ptr = Allocator.allocate(10);
		std::cout << "ptr address\t\t\t\t: " << (size_t *)ptr << '\n';
		Allocator.deallocate(ptr, 10);
	}

	std::cout << "\n\n";
	print_subtitle("-----");
	ft::map<int, int> map;
	int num;

	map[1] = 10;
	map[2] = 20;
	map[3] = 30;
	map[4] = 40;
	print_map(map, "Initial map:\n");

	// Element Access
	{
		print_subtitle("Element Access");
		num = map.at(3);
		std::cout << "map.at(3)\t\t\t\t: " << num << "\n";
		try
		{
			num = map.at(5);
		}
		catch (const std::exception &e)
		{
			std::cerr << "map.at(5)\t\t\t\t: ";
			std::cerr << e.what() << '\n';
		}
		std::cout << "map[2]\t\t\t\t\t: " << map[2] << '\n';
		std::cout << "map[5]\t\t\t\t\t: " << map[-10] << '\n'; // performs an insertion
	}

	// Iterators
	{
		print_subtitle("Iterators");

		ft::map<int, int>::iterator it;
		ft::map<int, int>::reverse_iterator itr;

		std::cout << "Iterator:\n";
		for (it = map.begin(); it != map.end(); it++)
			std::cout << it->first << " => " << it->second << '\n';
		std::cout << "\nReverse_iterator:\n";
		for (itr = map.rbegin(); itr != map.rend(); itr++)
			std::cout << itr->first << " => " << itr->second << '\n';
	}

	// Capacity
	{
		print_subtitle("Capacity");

		ft::map<size_t, int> map2;
		ft::map<int, size_t> map3;
		ft::map<size_t, size_t> map4;

		std::cout << std::boolalpha;
		std::cout << "map.empty() ?\t\t\t\t: " << map.empty() << '\n';
		std::cout << std::noboolalpha;
		std::cout << "map.size()\t\t\t\t: " << map.size() << '\n';
		std::cout << "map.max_size()\t\t\t\t: " << map.max_size() << '\n';
		std::cout << "map2.max_size()\t\t\t\t: " << map2.max_size() << '\n';
		std::cout << "map3.max_size()\t\t\t\t: " << map3.max_size() << '\n';
		std::cout << "map4.max_size()\t\t\t\t: " << map4.max_size() << '\n';
	}

	// Modifiers
	{
		print_subtitle("Modifiers");

		ft::map<int, int> map2;
		ft::map<int, int>::iterator it;
		std::pair<ft::map<int,int>::iterator, bool> pair1;

		map2[1] = 'a';
		map2[2] = 'b';
		map2[3] = 'c';
		map2[5] = 42;
		map2[5] = 24;

		print_map(map2, "map2:\n");

		map.clear();
		std::cout << "map.clear(), map.size()\t\t\t: " << map.size() << '\n';

		it = map2.find(3);
		pair1 = map.insert(*it); // overload 1: insert from lvalue reference
		printInsertionStatus(pair1.first, pair1.second, "map.insert(*it)\t\t\t\t: ");
		pair1 = map.insert(std::pair<int, int>(5, -99)); //overload1 maybe?
		printInsertionStatus(pair1.first, pair1.second, "map.insert(std::pair<int, int>(5, n))\t: ");
		pair1 = map.insert(std::pair<int, int>(5, -999999)); //overload1 fail
		printInsertionStatus(pair1.first, pair1.second, "map.insert(std::pair<int, int>(5, n))\t: ");
		map.insert(map2.begin(), map2.end()); // overload 7: no return value
		std::cout << "map.insert(map2.begin(), map2.end()), no return value\n"; // doesn't override pre-existing keys
		print_map(map, "After insert, map:\n");

		it = map.begin();
		map.erase((it + 1));
		print_map(map, "After erase, map:\n");
	}
}

int main()
{
	map_int();
}
