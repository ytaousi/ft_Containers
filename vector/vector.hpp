#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include "../iterators/reverse_iterator.hpp"
# include "../iterators/iterator.hpp"
# include "../iterators/iterator_traits.hpp"
# include <exception>
# include <iostream>
# include "../enable_if.hpp"
# include "../is_integral.hpp"
# include "../lexicographical_compare.hpp"
# include "../equal.hpp"

// VECTOR is implemented as sequence container representing arrays that can change in size

namespace ft
{  
    template <class T, class Alloc = std::allocator<T> >
    class Vector
    {
        public:
            typedef T                                               value_type;
            typedef Alloc                                           allocator_type;

            typedef	typename allocator_type::reference			    reference;
            typedef	typename allocator_type::const_reference	    const_reference;
            typedef	typename allocator_type::pointer			    pointer;
            typedef	typename allocator_type::const_pointer		    const_pointer;

            typedef ft::random_access_iterator<value_type>          iterator;
            typedef ft::random_access_iterator<const value_type>    const_iterator;
            typedef ft::reverse_iterator<iterator>                  reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>            const_reverse_iterator;

            typedef ptrdiff_t                                       difference_type;
            typedef size_t                                          size_type;
        // need to define the default/fill/range constructors : done    
        // Constructs an empty container, with no elements.
        explicit Vector (const allocator_type& alloc = allocator_type()) : _alloc(alloc), _size(0), _capacity(0), _array(NULL)
        {
            //std::cout << "Empty constructor Called" << std::endl;
        }

        // Constructs a container with n elements. Each element is a copy of val.
        explicit Vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _array(NULL), _alloc(alloc), _size(n), _capacity(n)
        {
            //std::cout << "Vector fill Constructor Called" << std::endl;
            //std::cout << "fill constructor Called" << std::endl;
            _array = _alloc.allocate(_capacity);
            for (size_type i = 0; i < n; i++)
                _alloc.construct(_array + i, val);
        }

        // Constructs a container with as many elements as the range [first,last), 
        //  with each element constructed from its corresponding element in that range, in the same order.
        template <class InputIterator>
        Vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type = InputIterator()) : _size(0), _capacity(0), _array(NULL) 
        {
            //std::cout << "range contructor called" << std::endl;
            // construct vector from input iterator(random_access_iterator)
            size_type difference = last - first;
            _size = difference;
            _capacity = difference;
            _array = _alloc.allocate(difference);
            for (size_type i = 0; i < difference; i++, first++)
                _alloc.construct(_array + i, *first); 
        }
        
        // copy constructor 
        Vector(const Vector& object) : _size(0), _capacity(0), _array(NULL), _alloc(allocator_type())
        {
            //std::cout << "Copy constructor Called" << std::endl;
            *this = object;
        }

        // assignement operator overloading
        Vector & operator=(const Vector& object)
        {
            //std::cout << "assignment operator overloading Called" << std::endl;
            
            _size = object.size();
            _capacity = object.capacity();
            _array = _alloc.allocate(_capacity);
            for (size_type i = 0; i < _size; ++i)
                _alloc.construct(_array + i, object[i]);
            return (*this);
        }
        
        // destructor
        ~Vector()
        {
            //std::cout << "Vector Destructor Called " << std::endl;
            if (_array)
                _alloc.deallocate(_array, _capacity);
        }
        
        // Member Fuctions

            // Iterator Function's

        iterator begin()
        {
            return iterator(_array);
        }
        
        const_iterator begin() const
        {
            return const_iterator(_array);
        }

        reverse_iterator rbegin()
        {
            return reverse_iterator(_array + _size);
        }
        const_reverse_iterator rbegin() const
        {
            return const_reverse_iterator(_array + _size);
        }

        iterator end()
        {
            return iterator(_array + _size);
        }

        const_iterator end() const
        {
            return const_iterator(_array + _size);
        }

        reverse_iterator rend()
        {
            return reverse_iterator(_array);
        }

        const_reverse_iterator rend() const
        {
            return const_reverse_iterator(_array); //
        }
            
            // Capacity Function's

        // return the number of elements in the vector (number of actual stored object in the vector) not 
        // necessarily equal to vector capacity        
        size_type size() const
        {
            return _size;
        }

        // return 
        size_type max_size() const
        {
            return _alloc.max_size(); // more logical thats the maximum possible value for size_t object's
        }
        // Not done yet
        void resize(size_type n, value_type val = value_type())
        {
            //Resizes the container so that it contains n elements.
            //If n is smaller than the current container size, the content is reduced to its first n elements, removing those beyond (and destroying them)
            //Notice that this function changes the actual content of the container by inserting or erasing elements from it.
            //If n is greater than the current container size, the content is expanded by inserting at the end as many elements as needed to reach a size of n. If val is specified, the new elements are initialized as copies of val, otherwise, they are value-initialized.
            //If n is also greater than the current container capacity, an automatic reallocation of the allocated storage space takes place.
            if (n <= _size)
            {
				for (size_type i = n + 1; i < _size ; i++)
					_alloc.destroy(&_array[i]);
				_size = n;
			}
            else 
            {
				//reserve for new capacity
                if (n > _capacity)
					reserve(n);
				for (size_type i = _size; i < n; i++)
					_alloc.construct(&_array[i], val);
				_size = n;
			}
        } 

        //
        size_type capacity() const
        {
            return _capacity;
        }

        //
        bool empty() const
        {
            if (_size == 0)
                return true ;
            else
                return false ;
        }

        // SEGFAULT Sometimes
        void reserve(size_type n)
        {
            if (n > _capacity)
            {
				value_type *tmp = _alloc.allocate(n);
				for (size_type i = 0; i < _size ; i++)
                {
					_alloc.construct(&tmp[i], _array[i]);
					_alloc.destroy(&_array[i]);
				}
                //check if 0 do not deallocate
				if (_capacity != 0)
					_alloc.deallocate(_array, _capacity);
				_array = tmp;
				_capacity = n;
			}
        }

            // element access function's
        
        //Returns a reference to the element at specified location pos. No bounds checking is performed.
        reference operator[] (size_type n)
        {
            return (_array[n]);
        }
        //Returns a reference to the element at specified location pos. No bounds checking is performed.
        const_reference operator[] (size_type n) const
        {
            return (_array[n]);
        }

        //Returns a reference to the element at specified location pos, with bounds checking.
        //If pos is not within the range of the container, an exception of type std::out_of_range is thrown.
        reference at (size_type n)
        {
            if (n < 0 || n >= _size)
                throw std::out_of_range("Out of Range");
            return (_array[n]);
        }

        //Returns a reference to the element at specified location pos, with bounds checking.
        //If pos is not within the range of the container, an exception of type std::out_of_range is thrown.
        const_reference at (size_type n) const
        {
            if (n < 0 || n >= _size)
                throw std::out_of_range("Out of Range");
            return (_array[n]);
        }

        //Returns a reference to the first element in the container.
        //Calling front on an empty container is undefined.
        reference front()
        {
            return (_array[0]);
        }

        //Returns a reference to the first element in the container.
        //Calling front on an empty container is undefined.
        const_reference front() const
        {
            return (_array[0]);
        }

        //Returns a reference to the last element in the container.
        //Calling back on an empty container causes undefined behavior.
        reference back()
        {
            return (_array[_size - 1]);
        }

        //Returns a reference to the last element in the container.
        //Calling back on an empty container causes undefined behavior.
        const_reference back() const
        {
            return (_array[_size - 1]);
        }

            // Element Modifiers function's
        
        //
        void clear()
        {
            //Erases all elements from the container. After this call, size() returns zero.
            //Invalidates any references, pointers, or iterators referring to contained elements. Any past-the-end iterators are also invalidated.  
            //Leaves the capacity() of the vector unchanged (note: the standard's restriction on the changes to capacity is in the specification of vector::reserve
            for (; _size > 0; _size--)
                _alloc.destroy(_array + (_size - 1));
        }

        //Exchanges the contents of the container with those of other. Does not invoke any move, copy, or swap operations on individual elements.
        //All iterators and references remain valid. The past-the-end iterator is invalidated.
        void swap (Vector& x)
        {
            // sizes may differ ?? so capacity also ?? hmmm
            std::swap(_capacity, x._capacity);
            std::swap(_size, x._size);
            std::swap(_array, x._array); 
        }

        //
        void pop_back()
        {
            //Removes the last element in the vector, effectively reducing the container size by one.
            //This destroys the removed element.
            _alloc.destroy(_array + (_size - 1));
            _size -= 1;
        }

        // segfault 3 / 10 wtf : fixed segfault
        void push_back (const value_type& val)
        {
            //if size is 0 reserve space for 1 unit
            // else if capacity equal size then reserve capacity * 2
            // insert element at index size
            // increment size by 1
            if (_size == 0)
                reserve (1);
            if (_size == _capacity)
                reserve(_capacity * 2);
            _alloc.construct(&_array[_size], val);
            _size++;
        }

        // need to declare  fuction's  assign()/erase()/insert() : done

        // range
        // segfault 1 / 10 wtf 
        template <class InputIterator>
        void assign (InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type = InputIterator())
        {
            size_type difference = last - first;

            if (difference > _size)
            {
                reserve(difference);
                _capacity = difference;
            }
            for (size_type i = 0; first != last;first++)
                _alloc.construct(&_array[i++], *first);
            for (size_type i = 0; i < _size; i++)
                _alloc.destroy(&_array[i]);
            _size = difference;
        }

        // all good
        void assign (size_type n, const value_type& val)
        {
            if ( n <= _size)
            {
                for (size_type i = 0; i < n; i++)
                    _alloc.construct(&_array[i] , val);
                _size = n;
            }
            if (n > _size)
            {
                reserve(n);
                for (size_type i = 0; i < n; i++)
                    _alloc.construct(&_array[i] , val);
                _capacity = n;
                _size = n;
            }
        }

        // erase single element using iterator
        iterator erase (iterator position)
        {
            return (erase(position, position + 1));
        }

        // erase range of elemets
        iterator erase (iterator first, iterator last)
        {
            size_type difference = last - first;
			size_type begin = first - this->begin();
            size_type end = last - this->begin();
 
            for(size_type i = begin; i < end; i++)
                _alloc.destroy(&_array[i]);
            size_type j = 0;
            for(size_type i = end; i < _size; i++)
            {
                _alloc.construct(&_array[begin + j], _array[end]);
                j++;
                end++;
            }
            _size -= difference;
			return (first);
        }

        //single element
        iterator insert (iterator position, const value_type& val)
        {
            insert(position, 1, val);
            return (position);
        }

        // fill
        void insert (iterator position, size_type n, const value_type& val)
        {
            
        }
        // range
        // template <class MyIterator>
        // void inset (iterator position, MyIterator first, MyIterator last)
        template <class InputIterator>
        void insert (iterator position, InputIterator first, InputIterator last)
        {

        }
            // Alloctor function
        
        // return a copy of the allocator object associated with the vector
        allocator_type get_allocator() const
        {
            return (_alloc);
        }

            // friend function for vector
            template <class TT, class AAlloc>
        friend bool operator== (const Vector<TT,AAlloc>& lhs, const Vector<TT,AAlloc>& rhs);
            template <class TT, class AAlloc>
        friend bool operator!= (const Vector<TT,AAlloc>& lhs, const Vector<TT,AAlloc>& rhs);
            template <class TT, class AAlloc>
        friend bool operator<  (const Vector<TT,AAlloc>& lhs, const Vector<TT,AAlloc>& rhs);
            template <class TT, class AAlloc>
        friend bool operator<= (const Vector<TT,AAlloc>& lhs, const Vector<TT,AAlloc>& rhs);
            template <class TT, class AAlloc>
        friend bool operator>  (const Vector<TT,AAlloc>& lhs, const Vector<TT,AAlloc>& rhs);
            template <class TT, class AAlloc>
        friend bool operator>= (const Vector<TT,AAlloc>& lhs, const Vector<TT,AAlloc>& rhs);
            
            template <class TT, class AAlloc>
        friend void swap (Vector<TT,AAlloc>& x, Vector<TT,AAlloc>& y);

        private:
            allocator_type _alloc;
            size_type      _size;
            size_type      _capacity;
            pointer     _array;
    };

    // Non-member function's

    //
    template <class T, class Alloc>
    void swap (Vector<T,Alloc>& x, Vector<T,Alloc>& y)
    {
        x.swap(y);
    }

    // 
    template <class T, class Alloc>
    bool operator== (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
    {
        if (lhs.size() != rhs.size())
		    return false;
	    return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
    }

    template <class T, class Alloc>
    bool operator!= (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
    {
        if (lhs == rhs)
            return false;
        return true;
    }

    template <class T, class Alloc>
    bool operator<  (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
    {
	    return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
    }

    template <class T, class Alloc>
    bool operator<= (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
    {
        if (lhs == rhs || lhs < rhs)
            return true;
        return false;
    }

    template <class T, class Alloc>
    bool operator>  (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
    {
	    return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
    }

    template <class T, class Alloc>
    bool operator>= (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
    {
        if (lhs == rhs || lhs > rhs)
            return true;
        return false;
    }
}
#endif