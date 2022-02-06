#ifndef STACK_HPP
# define STACK_HPP

# include <vector>

namespace ft
{
    template <class T, class Container = std::vector<T> >
    class stack;
}

template <class T, class Container = std::vector<T>>
class ft::stack
{
    // Type of the elements (T) first template parameter
    typedef T           value_type;
    // Type of underlying container second template parameter
    typedef Container   container_type;
    // an unsigned intergal type
    typedef size_t      size_type;

    public:
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

        void pop();

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