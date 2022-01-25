# ft_containers

### To Do

1. Stack
   - `free` memory for `ft::stack<std::string>` instances
   - create arithmetic operators
   - test with other data types
   - `<int> stacks` won't have seg fault when `pop()` empty stack, but `<std::string> stacks` will seg fault
   - include `member types`
2. Class naming method: `ft::vector` or `ft::Vector`?
3. Vector
   - unused member types
     - typedef std::ptrdiff_t difference_type;
     - typedef const T \*const_pointer;
4. Let VectorIterator work with <char> & <long>, eg: `ft::vector<char>::iterator it;`

### Resources

#### Stack structure reference

[GeeksforGeeks](https://www.geeksforgeeks.org/stack-data-structure-introduction-program/)

#### Vector structure reference

[GeeksforGeeks](https://www.geeksforgeeks.org/how-to-implement-our-own-vector-class-in-c/)

#### Sample vector source code

[Miguel GitHub](https://github.com/Miguel-Deniz/Vector-Implementation/blob/master/Vector%20Implementation/Vector.h)

#### const position and its meaining

- `int *` - pointer to int
- `int const *` - pointer to const int
- `int * const` - const pointer to int
- `int const * const` - const poinVter to const int

And the first `const can be on either side of the type

- `const int *` == `int const *`
- `const int * const` == `int const * const`

[source](https://stackoverflow.com/questions/1143262/what-is-the-difference-between-const-int-const-int-const-and-int-const)

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

### Notes

- `ft::vector<T>::insert(iterator pos, size_type count, const T &value)` had to be modified to `ft::vector<T>::insert(iterator pos, T count, const T &value)` to avoid function call being caught by `ft::vector<T>::insert(iterator pos, InputIt first, InputIt last)`
  - also, `explicit vector(T count, const T &value = T(), const Allocator &alloc = Allocator());`, which is supposed to be `size_type count`
