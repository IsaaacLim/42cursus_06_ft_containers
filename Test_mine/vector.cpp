#include "vector.hpp"
#include "VectorIterator.hpp"
#include <iostream>

#define YELLOW "\033[0;33m"
#define PURPLE "\033[0;35m"
#define RESET "\033[0m"

using namespace std;
void print_title(string str)
{
	cout << YELLOW;
	cout << "=============== " << str << " ===============" << endl;
	cout << RESET;
}

void print_subtitle(string str)
{
	cout << PURPLE;
	cout << "--------------- " << str << " ---------------" << endl;
	cout << RESET;
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

	cout << "end: " << *(vec.end()) << '\n';
	cout << "Arr: ";
	vec.print();

	print_subtitle("Modifiers");
	{
		vec.push_back(60);
		vec.print();
		vec.erase(vec.begin());
		vec.print();
		vec.erase(vec.begin() + 1, vec.begin() + 4);
		vec.print();
		vec.pop_back();
		vec.print();
		vec.push_back(10);
		vec.push_back(20);
		vec.push_back(30);
		vec.push_back(40);
		vec.print();
		vec.resize(3);
		vec.print();
		vec.resize(5);
		vec.print();
		vec.resize(8, 100);
		vec.print();
		vec.resize(8, 1000);
		vec.print();
		vec.insert(vec.begin() + 2, 200);
		vec.print();
		it = vec.insert(vec.begin() + 9, 200); //insert at the end is OK too
		vec.print();
		std::cout << *it << '\n';
		vec.insert(vec.begin() + 11, 2, -1); //over limit, lib will seg fault, mine just returns
		vec.print();
		vec.insert(vec.begin() + 10, 2, -1);
		vec.print();
		ft::vector<int> vec2;
		vec2.push_back(1);
		vec2.push_back(2);
		vec2.push_back(3);
		// vec.insert(vec.begin() + 11, vec2.begin(), vec2.end()); //works, no problem
		vec.swap(vec2);
		vec.print();
		vec2.print();
		vec.clear();
		vec.print();
	}

	print_subtitle("Iterator (simple)");
}

int main()
{
	// vector_iterator(); //done
	vector_int();
}
