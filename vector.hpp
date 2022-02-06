#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>

// VECTOR is implemented as sequence

namespace ft
{
    template <class T, class Alloc = std::allocator<T> >
    class vector;
}

template <class T, class Alloc>
class ft::vector
{
    public:
        typedef T                                           value_type;
        typedef size_t                                      size_type;
        typedef Alloc                                       allocator_type;
        typedef typename allocator_type::reference          reference;
        typedef typename allocator_type::const_reference    const_reference;
        typedef typename allocator_type::pointer            pointer;
        typedef typename allocator_type::const_pointer      const_pointer;

        // need to typedef the iterators type

    // need to define the default/fill/range constructors

    // copy constructor 1/4
    vector(const ft::vector& object)
    {

    }

    // assignement operator overloading
    ft::vector & operator=(const ft::vector& object)
    {

    }
    
    // destructor
    ~vector()
    {
        ;
    }
    
    // Member Fuctions

        // Iterator Function's
            // begin();
            // rbegin();
            // end();
            // rend();
        
        // Capacity Function's

    // return the number of elements in the vector (number of actual stored object in the vector) not 
    // necessarily equal to vector capacity        
    size_type size() const
    {

    }

    // return 
    size_type max_size() const
    {

    }

    //
    void resize(size_type n, value_type val = value_type())
    {

    } 

    //
    size_type capacity() const
    {

    }

    //
    bool empty() const
    {

    }

    //
    void reserve(size_type n)
    {

    }

        // element access function's
    
    //
    reference operator[] (size_type n)
    {

    }
    
    //
    const_reference operator[] (size_type n) const
    {

    }

    //
    reference at (size_type n)
    {

    }

    //
    const_reference at (size_type n) const
    {

    }

    //
    reference front()
    {

    }

    //
    const_reference front() const
    {

    }

    //
    reference back()
    {

    }

    //
    const_reference back() const
    {

    }

        // Element Modifiers function's
    
    //
    void clear()
    {

    }

    //
    void swap (ft::vector& x)
    {

    }

    //
    void pop_back()
    {

    }

    //
    void push_back (const value_type& val)
    {

    }

    // need to declare  fuction's  assign()/erase()/insert()

        // Alloctor function
    
    // return a copy of the allocator object associated with the vector
    allocator_type get_allocator() const
    {

    }
};
#endif