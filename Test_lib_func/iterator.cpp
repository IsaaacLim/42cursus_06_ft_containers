#include <vector>
#include <limits>

#include <iostream>
int main(void)
{
	std::vector<long> arr;
	std::vector<long>::iterator i;
	std::vector<long>::iterator j;
	std::vector<long>::reverse_iterator m;

	std::cout << arr.max_size() << '\n';

	arr.push_back(100);
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(4);
	arr.push_back(5);

	size_t max = std::numeric_limits<size_t>::max();
	size_t max_size = max / sizeof(long);
	std::cout << max_size << '\n';

	i = arr.begin(); //1
	std::cout << *i << '\n';

	arr.erase(i);

	std::cout << *i << '\n';


	// // i = arr[2]; // NOPE

	// i++;
	// std::cout << *i << '\n'; //2
	// ++i;
	// std::cout << *i << '\n'; //3
	// std::cout << *i++ << '\n'; //3
	// std::cout << *i << '\n'; //4
	// std::cout << *++i << '\n'; //5
	// std::cout << *++i << '\n'; //undefined
	// std::cout << *++i << '\n'; //undefined

	// i -= 4;
	// std::cout << *i << '\n'; //takes into account 2 undefined too

	// i -= 10;
	// std::cout << *i << '\n';
	// i--;
	// i--;
	// i -= 2;
	// i += 3;
	// i += 1;
	// i += 10;
	// std::cout << *i << '\n';

	// std::cout << i[+2] << '\n';
	// std::cout << i[-2] << '\n';
	// std::cout << i[-20] << '\n';
	// std::cout << *i << '\n';


	// std::cout << "OTHER\n";
	// i = arr.begin();
	// j = i + 3;

	// std::cout << *j << '\n';

	// j += -3;
	// std::cout << *j << '\n';
	// std::cout << *(j + 2) << '\n';
	// std::cout << *(j -10)<< '\n';

	// i = arr.begin();
	// j = arr.begin();

	// i++;
	// if (i > j)
	// 	std::cout << "more than\n";
	// else
	// 	std::cout << "meh\n";

	m = arr.rbegin();
	std::cout << *m++ << '\n';
	std::cout << *m << '\n';
}
