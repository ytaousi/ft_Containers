#ifndef ENABLE_IF_HPP
# define ENABLE_IF_HPP

// enable_if can be used in many forms, including:
// as an additional function argument (not applicable to operator overloads)
// as a return type (not applicable to constructors and destructors)
// as a class template or function template parameter 
// example piece of code to test
// https://en.cppreference.com/w/cpp/types/enable_if
// common usage with is_integral
namespace ft
{
    template< bool B, class T = void>
    struct enable_if;

    template<class T>
    struct enable_if<true, T> { typedef T type; };
}

#endif