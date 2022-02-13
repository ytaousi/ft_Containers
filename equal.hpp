#ifndef EQUAL_HPP
# define EQUAL_HPP

//Test whether the elements in two ranges are equal
//Compares the elements in the range [first1,last1) with those in the range beginning at first2,
// and returns true if all of the elements in both ranges match.
// The elements are compared using operator==
//https://www.cplusplus.com/reference/algorithm/equal/
// piece of code to test
namespace ft
{
    template <class InputIterator1, class InputIterator2>
    bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
    {
        while (first1 != last1)
        {
            if (!(*first1 == *first2))
                return false;
            ++first1;
            ++first2;
        }
        return true;
    }
}

#endif