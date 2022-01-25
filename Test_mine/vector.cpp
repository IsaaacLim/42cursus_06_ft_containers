#include "vector.hpp"
#include "VectorIterator.hpp"
#include <iostream>
#include <vector>

#define YELLOW "\033[0;33m"
#define PURPLE "\033[0;35m"
#define RESET "\033[0m"

using namespace std;
void print_title(string str)
{
	cout << YELLOW;
	cout << "========================= " << str << " =========================" << endl;
	cout << RESET;
}

void print_subtitle(string str)
{
	cout << PURPLE;
	cout << "------------------------- " << str << " -------------------------" << endl;
	cout << RESET;
}

template <typename T, typename Allocator = std::allocator<T>>
void print_vector(ft::vector<T, Allocator> &vec, string str) //make for const &vec
{
	typename ft::vector<T, Allocator>::iterator it;

	if (!str.empty())
		cout << str;
	it = vec.begin();
	while (it != vec.end())
	{
		std::cout << *it << ' ';
		it++;
	}
	std::cout << '\n';
}

void vector_iterator()
{
	print_title("Vector Iterator");

	int arr[5] = {10, 20, 30, 40, 50};
	ft::VectorIterator<int> i;
	ft::VectorIterator<int> j;

	cout << "Arr: ";
	for (int i = 0; i < 5; i++)
		cout << arr[i] << ' ';
	cout << "\n\n";

	i = arr + 2;
	cout << "i = arr + 2\n";
	cout << "*i\t\t: " << *i << '\n';
	cout << "*(i + 2)\t: " << *(i + 2) << '\n';
	cout << "*(i + -2)\t: " << *(i + -2) << '\n';
	cout << "*(i - 1)\t: " << *(i - 1) << '\n';
	cout << "*(i - -1)\t: " << *(i - -1) << '\n';
	cout << "*i\t\t: " << *i << "\n\n";

	cout << "*i++\t\t: " << *i++ << '\n';
	cout << "*i--\t\t: " << *i-- << '\n';
	cout << "*i\t\t: " << *i << '\n';
	cout << "*++i\t\t: " << *++i << '\n';
	cout << "*--i\t\t: " << *--i << "\n\n";

	i += 1;
	cout << "i += 1,\t *i\t: " << *i << '\n';
	i += -1;
	cout << "i += -1, *i\t: " << *i << '\n';
	i -= 2;
	cout << "i -= -2, *i\t: " << *i << '\n';
	i -= -2;
	cout << "i -= 2,\t *i\t: " << *i << "\n\n";

	cout << "i[2]\t\t: " << i[2] << '\n';
	cout << "i[-1]\t\t: " << i[-1] << "\n\n";

	j = i;
	cout << "j = i\n";
	cout << "i == j ?\t: ";
	i == j ? cout << "True\n" : cout << "False\n";
	cout << "i != j ?\t: ";
	i != j ? cout << "True\n" : cout << "False\n";
	cout << "i > j ? \t: ";
	i > j ? cout << "True\n" : cout << "False\n";
	cout << "i >= j ?\t: ";
	i >= j ? cout << "True\n" : cout << "False\n";
	cout << "i < j ? \t: ";
	i < j ? cout << "True\n" : cout << "False\n";
	cout << "i <= j ?\t: ";
	i <= j ? cout << "True\n" : cout << "False\n";

	j++;
	cout << "j++\n";
	cout << "i == j ?\t: ";
	i == j ? cout << "True\n" : cout << "False\n";
	cout << "i != j ?\t: ";
	i != j ? cout << "True\n" : cout << "False\n";
	cout << "i > j ? \t: ";
	i > j ? cout << "True\n" : cout << "False\n";
	cout << "i >= j ?\t: ";
	i >= j ? cout << "True\n" : cout << "False\n";
	cout << "i < j ? \t: ";
	i < j ? cout << "True\n" : cout << "False\n";
	cout << "i <= j ?\t: ";
	i <= j ? cout << "True\n" : cout << "False\n";

	cout << '\n';
}

void vector_int()
{
	print_title("Vector (int)");
	ft::vector<int> vec;
	// ft::vector<int> vec99 {1,2,3}; //make this work
	ft::vector<int>::iterator it;

	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);
	vec.push_back(50);

	// cout << "end: " << *(vec.end()) << '\n'; //fix for valgrind
	cout << "Arr: ";
	print_vector(vec, "");

	// Element Access
	{
		print_subtitle("Element Access");
		cout << "at(4)\t\t\t\t\t: " << vec.at(4) << '\n';
		try
		{
			cout << "at(5)\t\t\t\t\t: " << vec.at(5) << '\n';
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
		cout << "vector[0]\t\t\t\t: " << vec[0] << '\n';
		cout << "vector[5]\t\t\t\t: " << vec[5] << '\n';
		cout << "vector[-1]\t\t\t\t: " << vec[-1] << '\n';
		cout << "front()\t\t\t\t\t: " << vec.front() << '\n';
		cout << "back()\t\t\t\t\t: " << vec.back() << '\n';
		int *arr = vec.data();
		cout << "int *arr = .data(), arr[i]\t\t: ";
		for (int i = 0; i < 5; i++)
			cout << arr[i] << ' ';
		cout << '\n';
	}

	// Capacity
	{
		ft::vector<int> vec2;
		std::vector<int> stdVec;

		print_subtitle("Capacity");

		if (vec.empty())
			cout << "a.empty()?\t\t\t\t: Yes\n";
		else
			cout << "a.empty()?\t\t\t\t: No\n";
		if (vec2.empty())
			cout << "b.empty()?\t\t\t\t: Yes\n";
		else
			cout << "b.empty()?\t\t\t\t: No\n";
		cout << "a.size()\t\t\t\t: " << vec.size() << '\n';
		cout << "b.max_size()\t\t\t\t: " << vec2.max_size() << '\n';
		cout << "ref.max_size()\t\t\t\t: " << stdVec.max_size() << '\n';
		cout << "b.capacity()\t\t\t\t: " << vec2.capacity() << '\n';
		vec2.reserve(10);
		cout << "b.reserve(10)\n";
		cout << "b.capacity()\t\t\t\t: " << vec2.capacity() << '\n';
	}

	// Modifiers
	{
		print_subtitle("Modifiers");

		ft::vector<int> vec2;
		vec2.push_back(-1);
		vec2.push_back(-2);
		vec2.push_back(-3);

		vec.push_back(60);
		print_vector(vec, "push_back(60)\t\t\t\t: ");
		vec.erase(vec.begin());
		print_vector(vec, "erase(.begin())\t\t\t\t: ");
		vec.erase(vec.begin() + 1, vec.begin() + 4);
		print_vector(vec, "erase(.begin() + 1, begin() + 4)\t: ");
		vec.pop_back();
		print_vector(vec, "pop_back()\t\t\t\t: ");
		vec.insert(vec.begin(), 100);
		print_vector(vec, "insert(.begin(), 100)\t\t\t: ");
		it = vec.insert(vec.begin() + 2, 200); //insert at the end is OK too
		print_vector(vec, "insert(.begin() + 2, 200)\t\t: ");
		std::cout << "*it returned from insert()\t\t: " << *it << '\n';
		vec.insert(vec.begin() + 4, 2, 300); //over limit, lib will seg fault, mine just returns
		print_vector(vec, "insert(.begin() + 4, 2, 300)\t\t: ");
		vec.insert(vec.begin() + 3, 2, 300);
		print_vector(vec, "insert(.begin() + 3, 2, 300)\t\t: ");
		vec.insert(vec.begin() + 4, vec2.begin(), vec2.end());
		print_vector(vec, "insert(.begin() + 4, b.begin(), b.end()): ");
		vec.resize(3);
		print_vector(vec, "resize(3)\t\t\t\t: ");
		vec.resize(6);
		print_vector(vec, "resize(6)\t\t\t\t: ");
		vec.clear();
		print_vector(vec, "clear()\t\t\t\t\t: ");
		vec.swap(vec2);
		print_vector(vec, "a.swap(b) - a\t\t\t\t: ");
		print_vector(vec2, "a.swap(b) - b\t\t\t\t:");
	}

	print_subtitle("Iterator (simple)");
}

// #include <stdexcept>
int main()
{
	// vector_iterator(); //done
	vector_int();

	// try
	// {
	// 	int i = 0;

	// 	if (2 > i)
	// 		throw std::runtime_error("this is out of range");
	// 	else
	// 		cout << "alright\n";
	// }
	// catch (const std::exception &e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
}
