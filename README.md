# ft_containers

### Resources

#### friend function
```
#include <iostream>

using namespace std;

class Base {
private:
	int _x;

public:
	Base() {}
	Base(int x) : _x(x) {}
	friend void func(Base &);	//make this function a friend of this class
};

void func(Base &obj) {			//this function can access the private attribute
	obj.x = 20;
}

int main() {
	Base b(10);
	func(b);
}
```

#### std::allocator
Usage examples (here)[https://www.geeksforgeeks.org/stdallocator-in-cpp-with-examples/]

#### Iterator usage for vector
- To prevent invalidation (how to reassign)[https://thispointer.com//stdvector-and-iterator-invalidation/]
