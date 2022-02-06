#ifndef STACK_HPP
# define STACK_HPP

# include <vector>
# include <cstddef>

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

template <class T, class Container>
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
    // Destructor
    ~stack()
    {

    }

    // return true or false wheter the container is empty or not
    // it make a call to the method empty() of the underlying container
    bool empty() const
    {
        return (this->c.empty());
    }

    // return the size of the container
    // it make a call to the method size() of the underlying container
    size_type size() const
    {
        return (this->c.size());
    }
    
    // return a reference or contant reference
    //      to the element on the top of stack (last element added to stack)
    // it make a call to the method back() of the underlying container
    value_type& top()
    {
        return (this->c.back());
    }
    const value_type& top() const
    {
        return (this->c.back());
    }

    // insert an element on the stack
    // it make a call to the method push_back() of the underlying container
    void push (const value_type& val)
    {
        this->c.push_back(val);
    }

    // remove element on top of stack
    // it make a call to the method pop_back() of the underlying container
    void pop()
    {
        this->c.pop_back();
    }
    protected:
        container_type c;

};

// Non Member-Fuctions overloading

template <class T, class Container>
bool operator== (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
{
    return (lhs.c == rhs.c);
}

template <class T, class Container>
bool operator!= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
{
    return (lhs.c != rhs.c);
}

template <class T, class Container>
bool operator<  (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
{
    return (lhs.c < rhs.c);
}

template <class T, class Container>
bool operator<= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
{
    return (lhs.c <= rhs.c);
}
template <class T, class Container>
bool operator> (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
{
    return (lhs.c > rhs.c);
}
template <class T, class Container>
bool operator>= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
{
    return (lhs.c >= rhs.c);
}

#endif