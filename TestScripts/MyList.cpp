#include <iostream>
#include "MyList.hpp"
#define RED "\033[3;31m"
#define RESET "\033[0m"

void print_title(std::string str);
void print_subtitle(std::string str);
template <typename T>
void comparison_operator(const T &lhs, const T &rhs, std::string cont1, std::string cont2)
{
	std::cout << std::boolalpha << '\n';
	std::cout << cont1 << " == " << cont2 << "\t?\t: " << (lhs == rhs) << '\n';
	std::cout << cont1 << " != " << cont2 << "\t?\t: " << (lhs != rhs) << '\n';
	std::cout << cont1 << " < " << cont2 << "\t?\t: " << (lhs < rhs) << '\n';
	std::cout << cont1 << " <= " << cont2 << "\t?\t: " << (lhs <= rhs) << '\n';
	std::cout << cont1 << " > " << cont2 << "\t?\t: " << (lhs > rhs) << '\n';
	std::cout << cont1 << " >= " << cont2 << "\t?\t: " << (lhs >= rhs) << '\n';
	std::cout << std::noboolalpha;
}

void print_disclaimer()
{
	std::cout << RED "*List array is displayed as LIFO*\n" RESET;
}

template <typename T>
void print_list(T lst, std::string str)
{
	if (!str.empty())
		std::cout << str;
	while (!lst.empty())
	{
		std::cout << lst.back() << ' ';
		lst.pop_back();
	}
	std::cout << std::endl;
}

int main(void)
{
	print_title("My List");
	print_disclaimer();

	ft::MyList<int> lst;

	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);
	lst.push_back(40);
	lst.push_back(50);

	print_list(lst, "List: ");

	// Member Functions
	{
		print_subtitle("Member Functions");

		lst.push_back(-1);
		print_list(lst, "lst.push_back(-1)\t\t\t: ");
		lst.pop_back();
		print_list(lst, "lst.pop_back()\t\t\t\t: ");
		std::cout << "lst.back()\t\t\t\t: " << lst.back() << '\n';
		std::cout << "lst.size()\t\t\t\t: " << lst.size() << '\n';
		std::cout << std::boolalpha;
		std::cout << "lst.empty() ?\t\t\t\t: " << lst.empty() << '\n';
		while (!lst.empty())
			lst.pop_back();
		std::cout << "*pop_back until empty*, lst.empty() ?\t: " << lst.empty() << '\n';
		std::cout << std::noboolalpha;
	}
	// Non-member Functions
	{
		print_subtitle("Non-member Functions");
		print_disclaimer();

		ft::MyList<int> lst2;
		ft::MyList<int> lst3;
		ft::MyList<int> lst4;
		ft::MyList<int> lst5;

		lst.push_back(10);
		lst.push_back(20);
		lst.push_back(30);
		lst.push_back(40);
		lst.push_back(50);

		lst2 = lst;

		lst3.push_back(10);
		lst3.push_back(19); // smaller
		lst3.push_back(30);
		lst3.push_back(40);
		lst3.push_back(60); // larger

		lst4.push_back(10);
		lst4.push_back(21); // larger
		lst4.push_back(30);
		lst4.push_back(40);
		lst4.push_back(40); // smaller

		lst5.push_back(0);
		lst5.push_back(0);
		lst5.push_back(0);
		lst5.push_back(0);
		lst5.push_back(0);
		lst5.push_back(0); // extra

		print_list(lst, "List1: ");
		print_list(lst2, "List2: ");
		print_list(lst3, "List3: ");
		print_list(lst4, "List4: ");
		print_list(lst5, "List5: ");

		comparison_operator(lst, lst2, "List1", "List2");
		comparison_operator(lst, lst3, "List1", "List3");
		comparison_operator(lst, lst4, "List1", "List4");
		comparison_operator(lst, lst5, "List1", "List5");

		std::cout << "\nSwapped List2 with List3, List4 with List5\n";
		ft::swap(lst2, lst3);
		ft::swap(lst4, lst5);
		print_list(lst, "List1: ");
		print_list(lst2, "List2: ");
		print_list(lst3, "List3: ");
		print_list(lst4, "List4: ");
		print_list(lst5, "List5: ");
	}
	std::cout << std::endl;
}
