#include "vector.hpp"
#include "VectorIterator.hpp"
#include <iostream>

void vector_iterator()
{
	int arr[5] = {10, 20, 30, 40, 50};
	ft::VectorIterator<int> i;
	ft::VectorIterator<int> j;

	std::cout << "Arr: ";
	for (int i = 0; i < 5; i++)
		std::cout << arr[i] << ' ';
	std::cout << "\n\n";

	i = arr + 2;
	std::cout << "i = arr + 2\n";
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
	std::cout << "i -= -2, *i\t: " << *i << '\n';
	i -= -2;
	std::cout << "i -= 2,\t *i\t: " << *i << "\n\n";

	std::cout << "i[2]\t\t: " << i[2] << '\n';
	std::cout << "i[-1]\t\t: " << i[-1] << "\n\n";

	j = i;
	std::cout << "j = i\n";
	std::cout << "i == j ?\t: ";
	i == j ? std::cout << "True\n" : std::cout << "False\n";
	std::cout << "i != j ?\t: ";
	i != j ? std::cout << "True\n" : std::cout << "False\n";
	std::cout << "i > j ? \t: ";
	i > j ? std::cout << "True\n" : std::cout << "False\n";
	std::cout << "i >= j ?\t: ";
	i >= j ? std::cout << "True\n" : std::cout << "False\n";
	std::cout << "i < j ? \t: ";
	i < j ? std::cout << "True\n" : std::cout << "False\n";
	std::cout << "i <= j ?\t: ";
	i <= j ? std::cout << "True\n" : std::cout << "False\n";

	j++;
	std::cout << "j++\n";
	std::cout << "i == j ?\t: ";
	i == j ? std::cout << "True\n" : std::cout << "False\n";
	std::cout << "i != j ?\t: ";
	i != j ? std::cout << "True\n" : std::cout << "False\n";
	std::cout << "i > j ? \t: ";
	i > j ? std::cout << "True\n" : std::cout << "False\n";
	std::cout << "i >= j ?\t: ";
	i >= j ? std::cout << "True\n" : std::cout << "False\n";
	std::cout << "i < j ? \t: ";
	i < j ? std::cout << "True\n" : std::cout << "False\n";
	std::cout << "i <= j ?\t: ";
	i <= j ? std::cout << "True\n" : std::cout << "False\n";
}

int main()
{
	vector_iterator();
}
