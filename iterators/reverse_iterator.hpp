#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "iterator.hpp"
# include "iterator_traits.hpp"
// still need to define the iterator traits template
// so that typedef's takes in account
namespace ft
{
    template <class Iterator>
    class reverse_iterator
    {
        public:
            typedef Iterator                                                iterator_type;
            typedef typename iterator_traits<Iterator>::iterator_category   iterator_category;
            typedef typename iterator_traits<Iterator>::value_type          value_type;
            typedef typename iterator_traits<Iterator>::difference_type     difference_type;
            typedef typename iterator_traits<Iterator>::pointer             pointer;
            typedef typename iterator_traits<Iterator>::reference           reference;
        
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
            template <class IIterator>
            reverse_iterator (const reverse_iterator<IIterator>& rev_it)
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
            iterator_type rev_iter;
    };


// Non-member functions

    // addition operator
    template <class Iterator>
    reverse_iterator<Iterator> operator+ (typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it)
    {
        return (rev_it + n);
    }
    
    // substraction operator
    template <class Iterator>
    typename reverse_iterator<Iterator>::difference_type operator- (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base() - rhs.base());
    }

    // relational operators
    template <class Iterator>
    bool operator== (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base() == rhs.base());
    }

    template <class Iterator>
    bool operator!= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base() != rhs.base());
    }

    template <class Iterator>
    bool operator<  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base() < rhs.base());
    }

    template <class Iterator>
    bool operator<= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base() <= rhs.base());
    }

    template <class Iterator>
    bool operator>  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base() > rhs.base());
    }

    template <class Iterator>
    bool operator>= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base() >= rhs.base());
    }
}
#endif