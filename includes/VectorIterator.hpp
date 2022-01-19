#ifndef VECTORITERATOR_HPP
# define VECTORITERATOR_HPP

namespace ft
{
	template <class T>
	class VectorIterator
	{
	public:
		typedef T value_type;
		typedef T &reference; // ??
		typedef T *pointer; // ??

	protected:
		pointer _ptr;

	public:
		VectorIterator(void);
		VectorIterator(pointer ptr);
		~VectorIterator(void);
		VectorIterator(VectorIterator const &other);

		VectorIterator &operator=(VectorIterator const &other);
		//value_type *operator->(void); //vector->it ??
		value_type &operator*(void); // *it ??

		VectorIterator operator+(int const n);	//it + 2
		VectorIterator operator-(int const n);	//it - 2

		VectorIterator operator++(value_type);	// it++
		VectorIterator operator--(value_type);	// it--
		VectorIterator &operator++(void); 		// ++it
		VectorIterator &operator--(void); 		// --it

		VectorIterator &operator+=(int const n);
		VectorIterator &operator-=(int const n);
		value_type &operator[](int n);		// it[n]

		bool operator==(VectorIterator const &other) const;
		bool operator!=(VectorIterator const &other) const;
		bool operator>(VectorIterator const &other) const;
		bool operator>=(VectorIterator const &other) const;
		bool operator<(VectorIterator const &other) const;
		bool operator<=(VectorIterator const &other) const;
	};

}

template <class T>
ft::VectorIterator<T>::VectorIterator(void) { std::cout << "void constructor\n";}

template <class T>
ft::VectorIterator<T>::VectorIterator(pointer ptr) : _ptr(ptr) { std::cout << "another constructor\n"; }

template <class T>
ft::VectorIterator<T>::~VectorIterator(void) {}

template <class T>
ft::VectorIterator<T>::VectorIterator(const VectorIterator &other)
{
	this->_ptr = other._ptr;
}

template <class T>
ft::VectorIterator<T> &ft::VectorIterator<T>::operator=(VectorIterator const &other)
{
	std::cout << "'operator='\n";
	this->_ptr = other._ptr;
	return (*this);
}

template <class T>
// T = typename ft::VectorIterator<T>::value_type
T &ft::VectorIterator<T>::operator*(void)
{
	return (*(this->_ptr));
}

template <class T>
ft::VectorIterator<T> ft::VectorIterator<T>::operator+(int const n)
{
	std::cout << "'operator+'\n";
	int i;

	i = n;
	VectorIterator tmp(*this);
	while (n > 0 && --i >= 0)
		tmp._ptr++;
	while (n < 0 && ++i <= 0)
		tmp._ptr--;
	return (tmp);
}

template <class T>
ft::VectorIterator<T> ft::VectorIterator<T>::operator-(int const n)
{
	std::cout << "'operator-'\n";
	int i;

	i = n;
	VectorIterator tmp(*this);
	while (n > 0 && --i >= 0)
		tmp._ptr--;
	while (n < 0 && ++i <= 0)
		tmp._ptr++;
	return (tmp);
}

template <class T>
ft::VectorIterator<T> ft::VectorIterator<T>::operator++(T)
{
	std::cout << "'operator++'\n";
	VectorIterator tmp(*this);
	this->_ptr++;
	return (tmp);
}

template <class T>
ft::VectorIterator<T> ft::VectorIterator<T>::operator--(T)
{
	std::cout << "'operator--'\n";
	VectorIterator tmp(*this);
	this->_ptr--;
	return (tmp);
}

template <class T>
ft::VectorIterator<T> &ft::VectorIterator<T>::operator++(void)
{
	std::cout << "'++operator'\n";
	this->_ptr++;
	return (*this);
}

template <class T>
ft::VectorIterator<T> &ft::VectorIterator<T>::operator--(void)
{
	std::cout << "'--operator'\n";
	this->_ptr--;
	return (*this);
}

template <class T>
ft::VectorIterator<T> &ft::VectorIterator<T>::operator+=(int const n)
{
	std::cout << "'operator+='\n";
	int i;

	i = n;
	while (n > 0 && --i >= 0)
		this->_ptr++;
	while (n < 0 && ++i <= 0)
		this->_ptr--;
	return (*this);
}

template <class T>
ft::VectorIterator<T> &ft::VectorIterator<T>::operator-=(int const n)
{
	std::cout << "'operator-='\n";
	int i;

	i = n;
	while (n > 0 && --i >= 0)
		this->_ptr--;
	while (n < 0 && ++i <= 0)
		this->_ptr++;
	return (*this);
}

template <class T>
T &ft::VectorIterator<T>::operator[](int n)
{
	std::cout << "'operator[]\n";
	int i;

	i = n;
	VectorIterator tmp(*this);
	while (n > 0 && --i >= 0)
		tmp._ptr++;
	while (n < 0 && ++i <= 0)
		tmp._ptr--;
	return (*tmp);
}

template <class T>
bool ft::VectorIterator<T>::operator==(VectorIterator const &other) const
{
	return (this->_ptr == other._ptr);
}

template <class T>
bool ft::VectorIterator<T>::operator!=(VectorIterator const &other) const
{
	return (this->_ptr != other._ptr);
}

template <class T>
bool ft::VectorIterator<T>::operator>(VectorIterator const &other) const
{
	return (this->_ptr > other._ptr);
}

template <class T>
bool ft::VectorIterator<T>::operator>=(VectorIterator const &other) const
{
	return (this->_ptr >= other._ptr);
}

template <class T>
bool ft::VectorIterator<T>::operator<(VectorIterator const &other) const
{
	return (this->_ptr < other._ptr);
}

template <class T>
bool ft::VectorIterator<T>::operator<=(VectorIterator const &other) const
{
	return (this->_ptr <= other._ptr);
}

#endif
