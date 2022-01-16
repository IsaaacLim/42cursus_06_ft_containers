/*
** Illustration of std::allocator() function
*/

#include <memory>
#include <iostream>
#include <string>
#include <stdlib.h>

int main()
{
	//default allocator for ints
	{
		std::allocator<int> alloc;
		int *p;

		p = alloc.allocate(1); // space for one int
		alloc.deallocate(p, 1);		// remove space for one int

		p = alloc.allocate(5);	// space for five ints
		alloc.construct(p, 100);	// construct the 1st index;
		p[1] = 10;					// construct the 2nd index;
		alloc.construct(p + 2, 50);	// construct the 3rd index;
		p[6] = 999;					// ??????

		alloc.destroy(p + 1);		// ??????

		std::cout << "p[0]: " << *p << '\n';
		std::cout << "p[1]: " << p[1] << '\n';
		std::cout << "p[2]: " << *(p + 2) << '\n';
		std::cout << "p[6]: " << p[6] << " <- still works????\n"; // ??????
		alloc.deallocate(p, 5);		// remove space for five ints
	}
	// default allocator for strings
	{
		std::allocator<std::string> alloc;
		std::string *str = alloc.allocate(3);

		alloc.construct(str, "First");
		alloc.construct(str + 1, "Second");
		alloc.construct(str + 2, "Third");

		alloc.destroy(str + 1); // ??????

		std:: cout << str[0] << *(str + 1) << str[2] << '\n';

		//destroy 3 strings
		alloc.destroy(str);
		alloc.destroy(str + 1);
		alloc.destroy(str + 2);

		alloc.deallocate(str, 3);		// deallocate space for 3 strings
	}
	// system("leaks a.out");
}
