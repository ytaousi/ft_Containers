#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>

// VECTOR is implemented as sequence container representing arrays that can change in size

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

    // need to define the default/fill/range constructors : done
    
    // Constructs an empty container, with no elements.
    explicit vector (const allocator_type& alloc = allocator_type())
    {

    }

    // Constructs a container with n elements. Each element is a copy of val.
    explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
    {

    }

    // Constructs a container with as many elements as the range [first,last), 
    //  with each element constructed from its corresponding element in that range, in the same order.
    template <class InputIterator>
    vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
    {

    }

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
        
    }
    
    // Member Fuctions

        // Iterator Function's

    iterator begin()
    {

    }

    const_iterator begin() const
    {

    }

    reverse_iterator rbegin()
    {

    }
    const_reverse_iterator rbegin() const
    {

    }

    iterator end()
    {

    }

    const_iterator end() const
    {

    }

    reverse_iterator rend()
    {

    }

    const_reverse_iterator rend() const
    {

    }
        
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
    private:
        allocator_type _alloc;
};
#endif