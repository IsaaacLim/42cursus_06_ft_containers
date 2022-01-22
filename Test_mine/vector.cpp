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
	std::cout << '\n';

	i = arr;
	// std::cout << *i << '\n';
	// std::cout << *(i + 2) << '\n';
	// std::cout << *i << '\n';

	// i++;
	// std::cout << *i << '\n';
	// std::cout << *(i + -1) << '\n';
	// std::cout << *i << '\n';

	// i += 1;
	// std::cout << *i << '\n';
	// std::cout << *i << '\n';

	// i += -2;
	// std::cout << *i << '\n';
	// std::cout << *i << '\n';

	// i -= -2;
	// std::cout << *i << '\n';
	// std::cout << *(i - 2) << '\n';
	// std::cout << *i << '\n';

	// i -= 2;
	// std::cout << *i << '\n';
	// std::cout << *(i - -3) << '\n';
	// std::cout << *i << '\n';

	// i += 4;
	// std::cout << *i-- << '\n';
	// std::cout << *i << '\n';

	// std::cout << *++i << '\n';
	// std::cout << *--i << '\n';

	// i = arr;
	// std::cout << *i << '\n';
	// std::cout << i[2] << '\n';
	// i += 3;
	// std::cout << *i << '\n';
	// std::cout << i[-2] << '\n';

	i = arr;
	j = arr;

	// ++j;
	if (++i <= j)
		std::cout << "Less than\n";
	else
		std::cout << "opposite\n";

}

int main()
{
	vector_iterator();
}
