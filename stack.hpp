#ifndef STACK_HPP
# define STACK_HPP

# include <vector>

// STACK is implemented as an adaptive container it means it encapsulate
//  an object of specifice container class as its underlying container 

// The standard container classes  "vector", "list", "deque" can fullfill those requirements

// By default if no container is defined for a stack class instantiation  , the standard container "deque"
//  is used;

namespace ft
{
    template <class T, class Container = std::vector<T> >
    class stack;
}

template <class T, class Container = std::vector<T>>
class ft::stack
{
    public:
    // Type of the elements (T) first template parameter
    typedef T           value_type;
    // Type of underlying container second template parameter
    typedef Container   container_type;
    // an unsigned intergal type
    typedef size_t      size_type;
    
    // Members Fuctions

        // Constructor
    explicit stack (const container_type& ctnr = container_type())
    {

    }

    bool empty() const
    {

    }
        
    size_type size() const
    {

    }
        
    value_type& top()
    {

    }
        
    const value_type& top() const
    {

    }

    void push (const value_type& val)
    {
            
    }

    void pop()
    {

    }

};

// Non Member-Fuctions overloading

template <class T, class Container>
bool operator== (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
{

}

template <class T, class Container>
bool operator!= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
{

}

template <class T, class Container>
bool operator<  (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
{

}

template <class T, class Container>
bool operator<= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
{

}
template <class T, class Container>
bool operator> (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
{

}
template <class T, class Container>
bool operator>= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
{

}

#endif