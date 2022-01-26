#ifndef VECTORITERATOR_HPP
#define VECTORITERATOR_HPP

namespace ft
{
	template <class T>
	class VectorIterator
	{
	public:
		typedef T value_type;
		typedef T &reference;
		typedef T *pointer;

	protected:
		pointer _ptr;

	public:
		VectorIterator(void);
		VectorIterator(pointer ptr);
		VectorIterator(VectorIterator const &other);
		~VectorIterator(void);

		VectorIterator &operator=(VectorIterator const &other);
		pointer operator->(void);  //vector->it ??
		reference operator*(void); // *it

		VectorIterator operator+(int const n); //it + 2
		VectorIterator operator-(int const n); //it - 2

		VectorIterator operator++(int);	  // it++
		VectorIterator operator--(int);	  // it--
		VectorIterator &operator++(void); // ++it
		VectorIterator &operator--(void); // --it

		VectorIterator &operator+=(int const n);
		VectorIterator &operator-=(int const n);
		reference operator[](int n); // it[n]

		bool operator==(VectorIterator const &other) const;
		bool operator!=(VectorIterator const &other) const;
		bool operator>(VectorIterator const &other) const;
		bool operator>=(VectorIterator const &other) const;
		bool operator<(VectorIterator const &other) const;
		bool operator<=(VectorIterator const &other) const;
	};

	template <class T>
	class ReverseVectorIterator : public VectorIterator<T>
	{
	public:
		typedef T value_type;
		typedef T *pointer;
		typedef T &reference;

		ReverseVectorIterator(void);
		ReverseVectorIterator(pointer ptr);
		ReverseVectorIterator(ReverseVectorIterator const &other); // not needed, for canonical form only
		~ReverseVectorIterator(void);

		ReverseVectorIterator &operator=(ReverseVectorIterator const &other); // not needed, for canonical form only

		ReverseVectorIterator operator+(int const n);
		ReverseVectorIterator operator-(int const n);

		ReverseVectorIterator operator++(int);
		ReverseVectorIterator operator--(int);
		ReverseVectorIterator &operator++(void);
		ReverseVectorIterator &operator--(void);

		ReverseVectorIterator &operator+=(int const n);
		ReverseVectorIterator &operator-=(int const n);
		reference operator[](int n);

		bool operator>(ReverseVectorIterator const &other) const;
		bool operator>=(ReverseVectorIterator const &other) const;
		bool operator<(ReverseVectorIterator const &other) const;
		bool operator<=(ReverseVectorIterator const &other) const;

		/*
		  Functions inherited from parent
			reference operator*(void);
			pointer operator->(void);
			bool operator==(ReverseVectorIterator const &other) const;
			bool operator!=(ReverseVectorIterator const &other) const;
		*/
	};
}

// VECTOR ITERATOR =============================================================
template <class T>
ft::VectorIterator<T>::VectorIterator(void) {}

template <class T>
ft::VectorIterator<T>::VectorIterator(pointer ptr) : _ptr(ptr) {}

template <class T>
ft::VectorIterator<T>::VectorIterator(const VectorIterator &other)
{
	this->_ptr = other._ptr;
}

template <class T>
ft::VectorIterator<T>::~VectorIterator(void) {}

template <class T>
ft::VectorIterator<T> &ft::VectorIterator<T>::operator=(VectorIterator const &other)
{
	this->_ptr = other._ptr;
	return (*this);
}

template <class T>
// T = typename ft::VectorIterator<T>::value_type
T *ft::VectorIterator<T>::operator->(void)
{
	return (this->ptr);
}

template <class T>
T &ft::VectorIterator<T>::operator*(void)
{
	return (*(this->_ptr));
}

template <class T>
ft::VectorIterator<T> ft::VectorIterator<T>::operator+(int const n)
{
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
ft::VectorIterator<T> ft::VectorIterator<T>::operator++(int)
{
	VectorIterator tmp(*this);
	this->_ptr++;
	return (tmp);
}

template <class T>
ft::VectorIterator<T> ft::VectorIterator<T>::operator--(int)
{
	VectorIterator tmp(*this);
	this->_ptr--;
	return (tmp);
}

template <class T>
ft::VectorIterator<T> &ft::VectorIterator<T>::operator++(void)
{
	this->_ptr++;
	return (*this);
}

template <class T>
ft::VectorIterator<T> &ft::VectorIterator<T>::operator--(void)
{
	this->_ptr--;
	return (*this);
}

template <class T>
ft::VectorIterator<T> &ft::VectorIterator<T>::operator+=(int const n)
{
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

// REVERSE VECTOR ITERATOR =====================================================
template <class T>
ft::ReverseVectorIterator<T>::ReverseVectorIterator(void) {}

template <class T>
ft::ReverseVectorIterator<T>::ReverseVectorIterator(pointer ptr)
{
	this->_ptr = ptr;
}

template <class T>
ft::ReverseVectorIterator<T>::ReverseVectorIterator(const ReverseVectorIterator &other)
{
	this->_ptr = other._ptr;
}

template <class T>
ft::ReverseVectorIterator<T>::~ReverseVectorIterator(void) {}

template <class T>
ft::ReverseVectorIterator<T> &ft::ReverseVectorIterator<T>::operator=(ReverseVectorIterator const &other)
{
	this->_ptr = other._ptr;
	return (*this);
}

template <class T>
ft::ReverseVectorIterator<T> ft::ReverseVectorIterator<T>::operator+(int const n)
{
	int i;

	i = n;
	ReverseVectorIterator tmp(*this);
	while (n > 0 && --i >= 0)
		tmp._ptr--;
	while (n < 0 && ++i <= 0)
		tmp._ptr++;
	return (tmp);
}

template <class T>
ft::ReverseVectorIterator<T> ft::ReverseVectorIterator<T>::operator-(int const n)
{
	int i;

	i = n;
	ReverseVectorIterator tmp(*this);
	while (n > 0 && --i >= 0)
		tmp._ptr++;
	while (n < 0 && ++i <= 0)
		tmp._ptr--;
	return (tmp);
}

template <class T>
ft::ReverseVectorIterator<T> ft::ReverseVectorIterator<T>::operator++(int)
{
	ReverseVectorIterator tmp(*this);
	this->_ptr--;
	return (tmp);
}

template <class T>
ft::ReverseVectorIterator<T> ft::ReverseVectorIterator<T>::operator--(int)
{
	ReverseVectorIterator tmp(*this);
	this->_ptr++;
	return (tmp);
}

template <class T>
ft::ReverseVectorIterator<T> &ft::ReverseVectorIterator<T>::operator++(void)
{
	this->_ptr--;
	return (*this);
}

template <class T>
ft::ReverseVectorIterator<T> &ft::ReverseVectorIterator<T>::operator--(void)
{
	this->_ptr++;
	return (*this);
}

template <class T>
ft::ReverseVectorIterator<T> &ft::ReverseVectorIterator<T>::operator+=(int const n)
{
	int i;

	i = n;
	while (n > 0 && --i >= 0)
		this->_ptr--;
	while (n < 0 && ++i <= 0)
		this->_ptr++;
	return (*this);
}

template <class T>
ft::ReverseVectorIterator<T> &ft::ReverseVectorIterator<T>::operator-=(int const n)
{
	int i;

	i = n;
	while (n > 0 && --i >= 0)
		this->_ptr++;
	while (n < 0 && ++i <= 0)
		this->_ptr--;
	return (*this);
}

template <class T>
T &ft::ReverseVectorIterator<T>::operator[](int n)
{
	int i;

	i = n;
	ReverseVectorIterator tmp(*this);
	while (n > 0 && --i >= 0)
		tmp._ptr--;
	while (n < 0 && ++i <= 0)
		tmp._ptr++;
	return (*tmp);
}

template <class T>
bool ft::ReverseVectorIterator<T>::operator>(ReverseVectorIterator const &other) const
{
	return (this->_ptr < other._ptr);
}

template <class T>
bool ft::ReverseVectorIterator<T>::operator>=(ReverseVectorIterator const &other) const
{
	return (this->_ptr <= other._ptr);
}

template <class T>
bool ft::ReverseVectorIterator<T>::operator<(ReverseVectorIterator const &other) const
{
	return (this->_ptr > other._ptr);
}

template <class T>
bool ft::ReverseVectorIterator<T>::operator<=(ReverseVectorIterator const &other) const
{
	return (this->_ptr >= other._ptr);
}

#endif
