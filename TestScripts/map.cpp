#include <iostream>
#include <string>
#include <iomanip>
#include <cassert> // for assert()

#define YELLOW "\033[3;33m"
#define RESET "\033[0m"

#if 1
#include <map>
namespace ft = std;
#else
#include "map.hpp"
#endif

void print_title(std::string str);
void print_subtitle(std::string str);

template <typename T, typename U, typename V>
void print_map(ft::map<T, U, V> map, std::string str, bool space)
{
	typename ft::map<T, U, V>::iterator it;

	if (!str.empty())
		std::cout << str;
	for (it = map.begin(); it != map.end(); it++)
		std::cout << std::setw(5) << it->first << " | " << it->second << '\n';
	if (space)
		std::cout << '\n';
}

template <typename It>
void printInsertionStatus(It it, bool success, std::string str) // method from cppreference
{
	if (!str.empty())
		std::cout << str;
	std::cout << "Insertion of " << it->first << (success ? " succeeded\n" : " failed\n");
}

// WORKING HERE
template <typename T, typename U>
void comparison_operator(const T &lhs, const T &rhs, std::string cont1, std::string cont2)
{

}
// Example module 97 key compare function from cppreference.com's key_comp
struct ModCmp {
	bool operator()(const int lhs, const int rhs) const{
		return (lhs % 97) < (rhs %97);
	}
};

void map_int()
{
	print_title("Map");

	{ // Member Functions
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
		ft::map<int, int> map3(map);					// (3)
		ft::map<int, int, std::less<int> > map4 = map;	// (3)
		ft::map<char, int, std::greater<char> > map5;	// (1)
		ft::map<char, int, ModCmp> map6;
		// ft::map<int, int> map7(std::greater<int>); // can compile but can't modify
		// ft::map<int, int> map8(map.begin(), map.end(), ModCmp, alloc); // doesn't work

		map5['a'] = 1;
		map5['B'] = 10;
		map5['b'] = -20;
		map5['A'] = 100;

		print_map(map, "map:\n", 1);
		print_map(map2, "map2:\n", 1);
		print_map(map3, "map3:\n", 1);
		print_map(map4, "map4:\n", 1);
		print_map(map5, "map5:\n", 1);
		print_map(map6, "map6:\n", 1);

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
	print_map(map, "Initial map:\n", 1);

	{ // Element Access
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

	{ // Iterators
		print_subtitle("Iterators");

		ft::map<int, int>::iterator it;
		ft::map<int, int>::reverse_iterator itr;

		std::cout << "Iterator:\n";
		for (it = map.begin(); it != map.end(); it++)
			std::cout << it->first << " => " << it->second << '\n';
		std::cout << "\nReverse_iterator:\n";
		for (itr = map.rbegin(); itr != map.rend(); itr++)
			std::cout << itr->first << " => " << itr->second << '\n';

		// Notes: no += or -= operator
	}

	{ // Capacity
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

	{ // Modifiers
		print_subtitle("Modifiers");

		ft::map<int, int> map2;
		ft::map<int, int>::iterator it;
		std::pair<ft::map<int, int>::iterator, bool> pair1;

		map2[1] = 'a';
		map2[2] = 'b';
		map2[3] = 'c';
		map2[4] = 'd';
		map2[5] = 42;
		map2[5] = 24;
		map2[6] = 'f';
		map2[7] = 'g';
		map2[8] = 'h';

		print_map(map2, "map2:\n", 1);

		map.clear();
		std::cout << "map.clear(), map.size()\t\t\t: " << map.size() << "\n\n";

		it = map2.find(3);
		pair1 = map.insert(*it); // (1): insert from lvalue reference
		printInsertionStatus(pair1.first, pair1.second, "map.insert(*it)\t\t\t\t: ");
		pair1 = map.insert(std::pair<int, int>(5, -99)); // (1) maybe?
		printInsertionStatus(pair1.first, pair1.second, "map.insert(std::pair<int, int>(5, n))\t: ");
		pair1 = map.insert(std::pair<int, int>(5, -999999)); //(1) fail
		printInsertionStatus(pair1.first, pair1.second, "map.insert(std::pair<int, int>(5, n))\t: ");
		map.insert(map2.begin(), map2.end());									// (7): no return value
		std::cout << "map.insert(map2.begin(), map2.end()), no return value\n"; // doesn't override pre-existing keys
		print_map(map, "After insert, map:\n", 1);

		map.erase(++map.begin()); // (1)
		print_map(map, "map.erase(++map.begin()), map:\n", 0);
		it = --map.end();
		it--;
		map.erase(map.begin(), --it); // (2)
		print_map(map, "map.erase(map.begin(), it), map:\n", 0);
		std::cout << "map.erase(-1), n of element erased\t: " << map.erase(-1) << '\n'; // (3)
		std::cout << "map.erase(7), n of element erased\t: " << map.erase(7) << '\n';
		print_map(map, "map.erase(7), map:\n", 1);

		map.swap(map2);
		std::cout << "map.swap(map2)\n";
		print_map(map, "map:\n", 0);
		print_map(map2, "map2:\n", 1);
	}

	{ // Lookup
		print_subtitle("Lookup");

		ft::map<int, int>::iterator it;
		ft::map<int, int>::const_iterator const_it;
		std::pair<ft::map<int, int>::iterator, ft::map<int, int>::iterator> pair;
		std::pair<ft::map<int, int>::const_iterator, ft::map<int, int>::const_iterator> const_pair;

		std::cout << "map.count(2), 1 or 0\t\t\t: " << map.count(2) << '\n';
		std::cout << "map.count(-1), 1 or 0\t\t\t: " << map.count(-1) << '\n';

		it = map.find(5);
		const_it = map.find(8);
		if (it != map.end())
			std::cout << "map.find(5)\t\t\t\t: Found, " << it->first << " => " << (*it).second << '\n';
		else
			std::cout << "map.find(5)\t\t\t\t: Not Found\n";
		if (const_it != map.end())
			std::cout << "map.find(8)\t\t\t\t: Found, " << const_it->first << " => " << const_it->second << '\n';
		else
			std::cout << "map.find(8)\t\t\t\t: Not Found\n";

		std::cout << "map.equal_range():\n";
		pair = map.equal_range(2);
		for (it = pair.first; it != pair.second; ++it)
			std::cout << "\tmap[" << it->first << "] = " << it->second << '\n';
		if (pair.second == map.find(3))
			std::cout << "\tend of equal_range (pair.second) is one-past pair.first\n";
		else
			std::cout << "\tunexpected, pair.second expected to be one-past pair.first\n";
		map.erase(4); // erased key = 4
		std::cout << YELLOW"\t*map.erase(4)*\n"RESET;
		const_pair = map.equal_range(4); // this key is not present anymore
		if (const_pair.first == map.find(5))
			std::cout << "\tpair.first is iterator to first not-less than 4\n";
		else
			std::cout << "\tunexpected pair.first\n";
		if (const_pair.second == map.find(5))
			std::cout << "\tpair.second is iterator to first element greater-than 5\n";
		else
			std::cout << "\tunexpected pair.second\n";

		it = map.lower_bound(3);
		const_it = map.lower_bound(4); // this key is not present anymore
		std::cout << "map.lower_bound(3)\t\t\t: " << it->first << " => " << it->second << '\n';
		std::cout << "map.lower_bound(4)\t\t\t: " << const_it->first << " => " << const_it->second << '\n';

		it = map.upper_bound(3);
		const_it = map.upper_bound(5); // this key is not present anymore
		std::cout << "map.upper_bound(3)\t\t\t: " << it->first << " => " << it->second << '\n';
		std::cout << "map.upper_bound(5)\t\t\t: " << const_it->first << " => " << const_it->second << '\n';

	}

	{ // Observers
		print_subtitle("Observers");

		ft::map<int, char, ModCmp> map_cmp;
		ft::map<int, char, ModCmp>::key_compare key_comp_func;
		ft::map<int, char, ModCmp>::value_compare val_comp_func = map_cmp.value_comp();
		ft::map<int, char, ModCmp>::iterator it;
		std::pair<int, char> val;
		bool before;
		bool after;

		key_comp_func = map_cmp.key_comp();
		map_cmp[1] = 'a';
		map_cmp[2] = 'b';
		map_cmp[3] = 'c';
		map_cmp[4] = 'd';
		map_cmp[5] = 'e';
		print_map(map_cmp, "map_cmp:\n", 1);

		std::cout << "using map_cmp.key_comp():\n";
		for (it = map_cmp.begin(); it != map_cmp.end(); it++)
		{
			before = key_comp_func(it->first, 100);
			after = key_comp_func(100, it->first);
			std::cout << "\t(" << it->first << "," << it->second;
			if (!before && !after)
				std::cout << ") equivalent to key 100\n";
			else if (before)
				std::cout << ") goes before key 100\n";
			else if (after)
				std::cout << ") goes after key 100\n";
			else
				assert(0); // Cannot happen
		}

		std::cout << "using map_cmp.value_comp():\n";
		val.first = 100;
		val.second = 'a';
		for (it = map_cmp.begin(); it != map_cmp.end(); it++)
		{
			before = val_comp_func(*it, val);
			after = val_comp_func(val, *it);
			std::cout << "\t(" << it->first << "," << it->second;
			if (!before && !after)
				std::cout << ") equivalent to key " << val.first << '\n';
			else if (before)
				std::cout << ") goes before key " << val.first << '\n';
			else if (after)
				std::cout << ") goes after key " << val.first << '\n';
			else
				assert(0); // Cannot happen
		}

	}

	{ // Non-member functions
		print_subtitle("Non-member Functions");

		ft::map<int, int> map2, map3, map4;

		map2 = map3 = map4 = map;
		print_map(map, "map1:\n", 0);
		print_map(map2, "map2:\n", 0);
		print_map(map3, "map3:\n", 0);
		print_map(map4, "map4:\n", 1);
		std::cout <<
	}
}

int main()
{
	map_int();
}
