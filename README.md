# ft_containers

### To Do

0. MyList

   - Copy constructor doesn't free pre-existing list, but Lib's stack would. eg:

   ```
   ft::MyList<int> lst;
   ft::MyList<int> lst2;
   ft::MyList<int> lst3;

   lst.push(bla bla bla); ...
   lst2 = lst;
   lst3 = lst; // Not freed
   lst3 = lst2;
   ```

   (won't have any issues if the first copy was to a blank `MyList`)

1. Stack
   - `<int> stacks` won't have seg fault when `pop()` empty stack, but `<std::string> stacks` will seg fault
   - `stack<int, ft::vector<int>>`: no matching constructor within `ft::vector`
   - `<std::string>` only works in Mac. But will leak if over 23 characters.
2. Class naming method: `ft::vector` or `ft::Vector`?
3. Vector

   - unused member types

     - `typedef std::ptrdiff_t difference_type;`
     - `typedef const T \*const_pointer;`
     - `typedef const ft::ReverseVectorIterator<T> const_reverse_iterator;`

   - Data types
     - std::string gives segfault from push_back (testint at `vector_iterator_types()`)

4. VectorIterator
   - how to invoke the `operator->`?
5. Change `Makefile` to using -std=c++98, add spacing to `<<>>`, remove `Makefile` comments
6. Map
   - How to pass comparator function during initiation

### Resources

#### Stack

- [Structur reference](https://www.geeksforgeeks.org/stack-data-structure-introduction-program/)
- Relational operator compares the value in the stack **lexicographically**, hence, they will compare from the **first** element, NOT the top element.
- Was having issues using ft_vector as it's underlying container because the copy constructor (& operator = overload) wasn't declared with `const vector other`

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

- Usage examples [here](https://www.geeksforgeeks.org/stdallocator-in-cpp-with-examples/)
- for `std::string` values on a `std::string` container, segfault will occur without using a feature called [_placement new_](https://en.cppreference.com/w/cpp/language/new#Placement_new).

  - This will call constructor on a given pointer address
  - sample code

  ```
  this->_ptr = _alloc.allocate((this->_cap * sizeof(value_type)));
  for (size_type i = 0; i < this->_cap; i++)
     new (this->_ptr + i) value_type;

  ...

  for (size_type i = 0; i < this->cap; i++)
     (this->_ptr + i)->~value_type();
  _alloc.deallocate(this->ptr, this->_curr_len);
  ```

  - Without _placement new_, the segfault occurs when accessing `this->ptr[0]` after `_alloc.allocate` without doing the initialization
  - [stackoverflow ref](https://stackoverflow.com/questions/68239801/stdto-string-return-empty-string-when-using-stdallocator)

#### Iterator usage for vector

- To prevent invalidation [how to reassign](https://thispointer.com//stdvector-and-iterator-invalidation/)

#### map comparator

- default comparator is `less`
- other ways to go about it [here](https://linuxhint.com/map-comparator-c/)

### Notes

- `ft::vector<T>::insert(iterator pos, size_type count, const T &value)` had to be modified to `ft::vector<T>::insert(iterator pos, T count, const T &value)` to avoid function call being caught by `ft::vector<T>::insert(iterator pos, InputIt first, InputIt last)`
  - also, `explicit vector(T count, const T &value = T(), const Allocator &alloc = Allocator());`, which is supposed to be `size_type count`
