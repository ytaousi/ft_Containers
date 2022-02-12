#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "iterator.hpp"

namespace ft
{
    template <class Iteraor>
    class reverse_iterator;
}

class ft::reverse_iterator
{
    public:
        typedef Iterator        iterator_type;
        typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_category;
        typedef typename ft::iterator_traits<Iterator>::value_type        value_type;
        typedef typename ft::iterator_traits<Iterator>::difference_type   difference_type;
        typedef typename ft::iterator_traits<Iterator>::pointer           pointer;
        typedef typename ft::iterator_traits<Iterator>::reference         reference;
       
        // default Constructor
        // construct a reverse iterator that points to no object 
        //  the internal base iterator is value-initializaed
        reverse_iterator()
        {

        }

        // initialization
        // construct a reverse iterator from some original iterator it the behavior of the constructed object replicates the original
        // exept it iterates through its pointed elements in  the reverse order  
        explicit reverse_iterator (iterator_type it)
        {

        }
        // Copy
        // construct a reverse iterator from some other reverse iterator 
        // the constructed object keeps the same sense pf iteration as re_it
        template <class Iter>
        reverse_iterator (const reverse_iterator<Iter>& rev_it)
        {

        }

    // Member Function's

        //return base iterator
        iterator_type base() const
        {

        }

        //dereference iterator
        reference operator * () const
        {

        }

        //addition operator
        reverse_iterator operator+ (difference_type n) const
        {

        }

        //pre-increment iterator position
        // return the value after incrementation
        reverse_iterator& operator++()
        {

        }

        //post-incrementation
        // return the value before incrementation
        reverse_iterator operator++(int)
        {

        }

        //advance iterator
        reverse_iterator& operator+= (difference_type n)
        {

        }

        //substraction iterator
        reverse_iterator operator- (difference_type n) const
        {

        }

        //pre-decrement iterator position
        reverse_iterator& operator--()
        {

        }

        //post-decrementation
        reverse_iterator  operator--(int)
        {

        }

        //retrocede iterator
        reverse_iterator& operator-= (difference_type n)
        {

        }

        //dereference iterator
        pointer operator->() const
        {

        }

        //dereference iterator with offset
        reference operator[] (difference_type n) const
        {

        }
    private:
        iterator_type iter;
}

// Non-member functions

    // addition operator
    template <class Iterator>
    ft::reverse_iterator<Iterator> operator+ (typename ft::reverse_iterator<Iterator>::difference_type n, const ft::reverse_iterator<Iterator>& rev_it)
    {

    }
    
    // substraction operator
    template <class Iterator>
    typename ft::reverse_iterator<Iterator>::difference_type operator- (const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs)
    {

    }

    // relational operators
    template <class Iterator>
    bool operator== (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {

    }

    template <class Iterator>
    bool operator!= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {

    }

    template <class Iterator>
    bool operator<  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {

    }

    template <class Iterator>
    bool operator<= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {

    }

    template <class Iterator>
    bool operator>  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {

    }

    template <class Iterator>
    bool operator>= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        
    }

#endif