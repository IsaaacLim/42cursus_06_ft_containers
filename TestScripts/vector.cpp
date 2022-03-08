#include <iostream>
#if 0 // CREATE A REAL STL EXAMPLE
#include <vector>
namespace ft = std;
#else
#include "vector.hpp"
#endif

void print_title(std::string str);
void print_subtitle(std::string str);

template <typename T>
void print_vector(ft::vector<T> &vec, std::string str) // make for const &vec
{
	typename ft::vector<T>::iterator it;

	if (!str.empty())
		std::cout << str;
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
	print_title("Iterator");

	// Vector Iterator
	{
		print_subtitle("Vector Iterator");
		ft::vector<int> arr;
		ft::vector<int>::iterator i;
		ft::vector<int>::iterator j;

		arr.push_back(10);
		arr.push_back(20);
		arr.push_back(30);
		arr.push_back(40);
		arr.push_back(50);

		std::cout << "Arr: ";
		for (int i = 0; i < 5; i++)
			std::cout << arr[i] << ' ';
		std::cout << "\n\n";

		i = (arr.begin() + 2);
		std::cout << "i = arr.begin() + 2\n";
		std::cout << "*i\t\t: " << *i << '\n';
		std::cout << "*(i + 2)\t: " << *(i + 2) << '\n';
		std::cout << "*(i + -2)\t: " << *(i + -2) << '\n';
		std::cout << "*(i - 1)\t: " << *(i - 1) << '\n';
		std::cout << "*(i - -1)\t: " << *(i - -1) << '\n';
		std::cout << "*i\t\t: " << *i << "\n\n";

		std::cout << "*i++\t\t: " << *i++ << '\n';
		std::cout << "*i--\t\t: " << *i-- << '\n';
		std::cout << "*i\t\t: " << *i << '\n';
		std::cout << "*++i\t\t: " << *++i << '\n';
		std::cout << "*--i\t\t: " << *--i << "\n\n";

		i += 1;
		std::cout << "i += 1,\t *i\t: " << *i << '\n';
		i += -1;
		std::cout << "i += -1, *i\t: " << *i << '\n';
		i -= 2;
		std::cout << "i -= 2,\t *i\t: " << *i << '\n';
		i -= -2;
		std::cout << "i -= -2, *i\t: " << *i << "\n\n";

		std::cout << "i[2]\t\t: " << i[2] << '\n';
		std::cout << "i[-1]\t\t: " << i[-1] << "\n\n";

		j = i;
		std::cout << "j = i\n";
		std::cout << "i == j\t?\t: ";
		i == j ? std::cout << "True\n" : std::cout << "False\n";
		std::cout << "i != j\t?\t: ";
		i != j ? std::cout << "True\n" : std::cout << "False\n";
		std::cout << "i > j\t?\t: ";
		i > j ? std::cout << "True\n" : std::cout << "False\n";
		std::cout << "i >= j\t?\t: ";
		i >= j ? std::cout << "True\n" : std::cout << "False\n";
		std::cout << "i < j\t?\t: ";
		i < j ? std::cout << "True\n" : std::cout << "False\n";
		std::cout << "i <= j\t?\t: ";
		i <= j ? std::cout << "True\n" : std::cout << "False\n";

		j++;
		std::cout << "j++\n";
		std::cout << "i == j\t?\t: ";
		i == j ? std::cout << "True\n" : std::cout << "False\n";
		std::cout << "i != j\t?\t: ";
		i != j ? std::cout << "True\n" : std::cout << "False\n";
		std::cout << "i > j\t?\t: ";
		i > j ? std::cout << "True\n" : std::cout << "False\n";
		std::cout << "i >= j\t?\t: ";
		i >= j ? std::cout << "True\n" : std::cout << "False\n";
		std::cout << "i < j\t?\t: ";
		i < j ? std::cout << "True\n" : std::cout << "False\n";
		std::cout << "i <= j\t?\t: ";
		i <= j ? std::cout << "True\n" : std::cout << "False\n";
	}

	// Reverse Vector Iterator
	{
		print_subtitle("Reverse Vector Iterator");
		ft::vector<int> arr;
		ft::vector<int>::reverse_iterator i;
		ft::vector<int>::reverse_iterator j;

		arr.push_back(10);
		arr.push_back(20);
		arr.push_back(30);
		arr.push_back(40);
		arr.push_back(50);

		std::cout << "Arr: ";
		for (int i = 0; i < 5; i++)
			std::cout << arr[i] << ' ';
		std::cout << "\n\n";

		i = (arr.rbegin() + 2);
		std::cout << "i = arr.rbegin() + 2\n";
		std::cout << "*i\t\t: " << *i << '\n';
		std::cout << "*(i + 2)\t: " << *(i + 2) << '\n';
		std::cout << "*(i + -2)\t: " << *(i + -2) << '\n';
		std::cout << "*(i - 1)\t: " << *(i - 1) << '\n';
		std::cout << "*(i - -1)\t: " << *(i - -1) << '\n';
		std::cout << "*i\t\t: " << *i << "\n\n";

		std::cout << "*i++\t\t: " << *i++ << '\n';
		std::cout << "*i--\t\t: " << *i-- << '\n';
		std::cout << "*i\t\t: " << *i << '\n';
		std::cout << "*++i\t\t: " << *++i << '\n';
		std::cout << "*--i\t\t: " << *--i << "\n\n";

		i += 1;
		std::cout << "i += 1,\t *i\t: " << *i << '\n';
		i += -1;
		std::cout << "i += -1, *i\t: " << *i << '\n';
		i -= 2;
		std::cout << "i -= 2,\t *i\t: " << *i << '\n';
		i -= -2;
		std::cout << "i -= -2, *i\t: " << *i << "\n\n";

		std::cout << "i[2]\t\t: " << i[2] << '\n';
		std::cout << "i[-1]\t\t: " << i[-1] << "\n\n";

		j = i;
		std::cout << "j = i\n";
		std::cout << "i == j\t?\t: ";
		i == j ? std::cout << "True\n" : std::cout << "False\n";
		std::cout << "i != j\t?\t: ";
		i != j ? std::cout << "True\n" : std::cout << "False\n";
		std::cout << "i > j\t?\t: ";
		i > j ? std::cout << "True\n" : std::cout << "False\n";
		std::cout << "i >= j\t?\t: ";
		i >= j ? std::cout << "True\n" : std::cout << "False\n";
		std::cout << "i < j\t?\t: ";
		i < j ? std::cout << "True\n" : std::cout << "False\n";
		std::cout << "i <= j\t?\t: ";
		i <= j ? std::cout << "True\n" : std::cout << "False\n";

		j++;
		std::cout << "j++\n";
		std::cout << "i == j\t?\t: ";
		i == j ? std::cout << "True\n" : std::cout << "False\n";
		std::cout << "i != j\t?\t: ";
		i != j ? std::cout << "True\n" : std::cout << "False\n";
		std::cout << "i > j\t?\t: ";
		i > j ? std::cout << "True\n" : std::cout << "False\n";
		std::cout << "i >= j\t?\t: ";
		i >= j ? std::cout << "True\n" : std::cout << "False\n";
		std::cout << "i < j\t?\t: ";
		i < j ? std::cout << "True\n" : std::cout << "False\n";
		std::cout << "i <= j\t?\t: ";
		i <= j ? std::cout << "True\n" : std::cout << "False\n";
	}
	std::cout << '\n';
}

void vector_int()
{
	print_title("Vector (int)");
	ft::vector<int> vec;
	ft::vector<int>::iterator it;

	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);
	vec.push_back(50);

	print_vector(vec, "Main Vector: ");

	// Member Functions
	{
		print_subtitle("Member Functions");

		ft::vector<int> vec2;
		ft::vector<int> vec3(5, 10);
		ft::vector<int> vec4(5);
		std::allocator<size_t> alloc;
		ft::vector<int> vec5(alloc);
		ft::vector<int> vec6(vec.begin(), vec.end());
		ft::vector<int> vec7(vec);
		int *ptr = NULL;

		print_vector(vec2, "ft::vector<int> vec2\t\t\t: ");
		print_vector(vec3, "ft::vector<int> vec3(5, 10)\t\t: ");
		print_vector(vec4, "ft::vector<int> vec4(5)\t\t\t: ");
		print_vector(vec5, "ft::vector<int> vec5(alloc)\t\t: ");
		print_vector(vec6, "ft::vector<int> vec6(v.begin(), v.end()): ");
		print_vector(vec7, "ft::vector<int> vec7(v)\t\t\t: ");
		vec2.assign(8, 'a');
		print_vector(vec2, "assign(8, 'a')\t\t\t\t: ");
		vec2.assign(3, 'A');
		print_vector(vec2, "assign(3, 'A')\t\t\t\t: ");
		vec2.assign(vec.begin(), vec.end());
		print_vector(vec2, "assign(a.begin(), a.end())\t\t: ");
		std::cout << "ptr address\t\t\t\t: " << (size_t *)ptr << '\n';
		ptr = vec2.get_allocator().allocate(10);
		std::cout << "ptr address\t\t\t\t: " << (size_t *)ptr << '\n';
		vec2.get_allocator().deallocate(ptr, 10);
	}

	// Element Access
	{
		print_subtitle("Element Access");
		std::cout << "at(4)\t\t\t\t\t: " << vec.at(4) << '\n';
		try
		{
			std::cout << "at(5)\t\t\t\t\t: " << vec.at(5) << '\n';
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << "vector[0]\t\t\t\t: " << vec[0] << '\n';
		// std::cout << "vector[5]\t\t\t\t: " << vec[5] << '\n';   //OK but conditional jumps/ use of uninitialised values
		// std::cout << "vector[-1]\t\t\t\t: " << vec[-1] << '\n'; //OK but conditional jumps/ use of uninitialised values
		std::cout << "front()\t\t\t\t\t: " << vec.front() << '\n';
		std::cout << "back()\t\t\t\t\t: " << vec.back() << '\n';
		int *arr = vec.data();
		std::cout << "int *arr = .data(), arr[i]\t\t: ";
		for (int i = 0; i < 5; i++)
			std::cout << arr[i] << ' ';
		std::cout << '\n';
	}

	// Capacity
	{
		ft::vector<int> vec2;

		print_subtitle("Capacity");

		std::cout << std::boolalpha;
		std::cout << "a.empty()?\t\t\t\t: " << vec.empty() << "\n";
		std::cout << "b.empty()?\t\t\t\t: " << vec2.empty() << "\n";
		std::cout << std::noboolalpha;
		std::cout << "a.size()\t\t\t\t: " << vec.size() << '\n';
		std::cout << "b.max_size()\t\t\t\t: " << vec2.max_size() << '\n';
		std::cout << "b.capacity()\t\t\t\t: " << vec2.capacity() << '\n';
		vec2.reserve(10);
		std::cout << "b.reserve(10)\n";
		std::cout << "b.capacity()\t\t\t\t: " << vec2.capacity() << '\n';
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
		it = vec.insert(vec.begin() + 2, 200); // insert at the end is OK too
		print_vector(vec, "insert(.begin() + 2, 200)\t\t: ");
		std::cout << "*it returned from insert()\t\t: " << *it << '\n';
		vec.insert(vec.begin() + 4, 2, 300); // over limit, lib will seg fault, mine just returns
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

	// Iterators (simple version)
	{
		print_subtitle("Iterator (simple version)");

		ft::vector<int>::iterator it;
		ft::vector<int>::reverse_iterator rev_it;

		it = vec.begin();
		rev_it = vec.rbegin();

		std::cout << "vec.begin() & vec.end()\t\t\t: ";
		while (it != vec.end())
			std::cout << *it++ << ' ';
		std::cout << "\nvec.rbegin() & vec.rend()\t\t: ";
		while (rev_it != vec.rend())
			std::cout << *rev_it++ << ' ';
		std::cout << '\n';
	}

	// Non-member functions
	{
		print_subtitle("Non-member Functions");

		ft::vector<int> vec2;
		ft::vector<int> vec3;
		ft::vector<int> vec4;

		vec2.push_back(-1);
		vec2.push_back(-2);
		vec2.push_back(-3);
		vec3 = vec2;
		vec4 = vec2;
		vec3[2] = -4;
		vec4.push_back(0);

		print_vector(vec, "vec1: ");
		print_vector(vec2, "vec2: ");
		print_vector(vec3, "vec3: ");
		print_vector(vec4, "vec4: ");
		std::cout << '\n';

		std::cout << std::boolalpha;
		std::cout << "vec1 == vec2\t\t\t\t: " << (vec == vec2) << '\n';
		std::cout << "vec1 != vec2\t\t\t\t: " << (vec != vec2) << '\n';
		std::cout << "vec1 <  vec2\t\t\t\t: " << (vec < vec2) << '\n';
		std::cout << "vec1 <= vec2\t\t\t\t: " << (vec <= vec2) << '\n';
		std::cout << "vec1 >  vec2\t\t\t\t: " << (vec > vec2) << '\n';
		std::cout << "vec1 >= vec2\t\t\t\t: " << (vec >= vec2) << '\n';
		std::cout << '\n';
		std::cout << "vec1 == vec3\t\t\t\t: " << (vec == vec3) << '\n';
		std::cout << "vec1 != vec3\t\t\t\t: " << (vec != vec3) << '\n';
		std::cout << "vec1 <  vec3\t\t\t\t: " << (vec < vec3) << '\n';
		std::cout << "vec1 <= vec3\t\t\t\t: " << (vec <= vec3) << '\n';
		std::cout << "vec1 >  vec3\t\t\t\t: " << (vec > vec3) << '\n';
		std::cout << "vec1 >= vec3\t\t\t\t: " << (vec >= vec3) << '\n';
		std::cout << '\n';
		std::cout << "vec1 == vec4\t\t\t\t: " << (vec == vec4) << '\n';
		std::cout << "vec1 != vec4\t\t\t\t: " << (vec != vec4) << '\n';
		std::cout << "vec1 <  vec4\t\t\t\t: " << (vec < vec4) << '\n';
		std::cout << "vec1 <= vec4\t\t\t\t: " << (vec <= vec4) << '\n';
		std::cout << "vec1 >  vec4\t\t\t\t: " << (vec > vec4) << '\n';
		std::cout << "vec1 >= vec4\t\t\t\t: " << (vec >= vec4) << '\n';
		std::cout << std::noboolalpha;

		ft::swap(vec2, vec4);
		std::cout << "\nft::swap(vec2, vec4)\n";
		print_vector(vec, "vec1: ");
		print_vector(vec2, "vec2: ");
		print_vector(vec3, "vec3: ");
		print_vector(vec4, "vec4: ");
	}
}

void vector_data_types()
{
	print_title("Vector, other data types (simple test)");

	// Char
	{
		print_subtitle("Char");
		ft::vector<char> vec;
		ft::vector<char>::iterator it;

		vec.push_back(97);
		vec.push_back(98);
		vec.push_back('c');
		vec.push_back('d');
		vec.push_back(101);

		it = vec.begin();
		while (it != vec.end())
		{
			std::cout << *it << '\n';
			it++;
		}
	}

	// String
	{
		print_subtitle("String");
		ft::vector<std::string> vec_str;
		ft::vector<std::string>::iterator it;

		// vec_str.push_back("First"); //segfault at vector.hpp > push_back() > _arr[_current] = input;
		// vec_str.push_back("S e c o n d");
		// vec_str.push_back("1234567890");
		// vec_str.push_back("!@#$%^&*()_+=");
		// vec_str.push_back("END");

		it = vec_str.begin();
		while (it != vec_str.end())
		{
			std::cout << *it << '\n';
			it++;
		}
	}

	// Float
	{
		print_subtitle("Float");
		ft::vector<float> vec;
		ft::vector<float>::iterator it;

		vec.push_back(10);
		vec.push_back(-20.505f);
		vec.push_back(99e10f);
		vec.push_back(42e-3f);
		vec.push_back(-111e-6f);

		it = vec.begin();
		while (it != vec.end())
		{
			std::cout << *it << '\n';
			it++;
		}
	}

	// Double
	{
		print_subtitle("Double");
		ft::vector<double> vec;
		ft::vector<double>::iterator it;

		vec.push_back(10);
		vec.push_back(-20.505);
		vec.push_back(99e100);
		vec.push_back(42e-30);
		vec.push_back(-111e-60);

		it = vec.begin();
		while (it != vec.end())
		{
			std::cout << *it << '\n';
			it++;
		}
	}
}

int main()
{
	// vector_iterator();
	// vector_int();
	vector_data_types();

	/* Testing for ft::vector<std::string>
	std::allocator<std::string> alloc;
	std::string *arr;
	std::string str = "random";
	std::string &ref = str;

	arr = alloc.allocate(1);
	arr[0] = ref;

	std::cout << arr[0] << '\n';
	alloc.deallocate(arr, 1);
	*/
}
