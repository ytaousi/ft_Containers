#ifndef LEXICOGRAPHICAL_COMPARE_HPP
# define LEXICOGRAPHICAL_COMPARE_HPP

//Lexicographical comparison is a operation with the following properties:
//Two ranges are compared element by element.
//The first mismatching element defines which range is lexicographically less or greater than the other.
//If one range is a prefix of another, the shorter range is lexicographically less than the other.
//If two ranges have equivalent elements and are of the same length, then the ranges are lexicographically equal.
//An empty range is lexicographically less than any non-empty range.
//Two empty ranges are lexicographically equal. 

// No need to implement the second template funcion : it compare element using binary comparaison  comp();
//https://www.cplusplus.com/reference/algorithm/lexicographical_compare/
// piece of code te test
namespace ft
{
        //Checks if the first range [first1, last1) is lexicographically less than the second range [first2, last2)

    //Elements are compared using operator<.
    template< class InputIterator1, class InputIterator2 >
    bool lexicographical_compare( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2 )
    {
        while (first1!=last1)
        {
            if (first2 == last2 || *first2 < *first1)
                return false;
            else if (*first1 < * first2)
                return true;
            ++first1;
            ++first2;
        }
        return (first2 != last2);
    }
}

#endif