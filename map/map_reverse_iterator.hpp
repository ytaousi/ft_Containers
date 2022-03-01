#ifndef MAP_REVERSE_ITERATOR_HPP
#define MAP_REVERSE_ITERATOR_HPP

#include "map_iterator.hpp"
#include "map_iterator_traits.hpp"
#include <memory>

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
            reverse_iterator() : rev_iter(iterator_type()) // ??
            {

            }
            reverse_iterator(const reverse_iterator & other) : rev_iter(other.base() - 1)
            {
            }
            // initialization
            // construct a reverse iterator from some original iterator it the behavior of the constructed object replicates the original
            // exept it iterates through its pointed elements in  the reverse order  
            explicit reverse_iterator (const iterator_type & it)
            {
                iterator_type tmp = it;
                rev_iter = --tmp;
            }
            // Copy
            // construct a reverse iterator from some other reverse iterator 
            // the constructed object keeps the same sense pf iteration as rev_it
            template <class IIterator>
            reverse_iterator (const reverse_iterator<IIterator>& rev_it) : rev_iter(rev_it.base() - 1)
            {
            }

                // Member functions
            //return base iterator that was initialized with ??
            iterator_type base() const
            {
                iterator_type tmp = rev_iter;
                return ++tmp; // !!
            }

            //dereference iterator
            reference operator * () const
            {
                
            }

            //dereference iterator
            pointer operator->() const    //
            {
               
            }

            //pre-increment iterator position
            // return the value after incrementation
            reverse_iterator& operator++()
            {
                
            }

            //post-incrementation
            // return the value before incrementation
            reverse_iterator operator++(int)  //
            {
                
            }

            //pre-decrement iterator position
            reverse_iterator& operator--()//
            {
                
            }

            //post-decrementation
            reverse_iterator  operator--(int) //
            {
                
            }

            template <class IIterator>
            friend bool operator== (const reverse_iterator<IIterator>& lhs, const reverse_iterator<IIterator>& rhs);
                template <class IIterator>
            friend bool operator!= (const reverse_iterator<IIterator>& lhs, const reverse_iterator<IIterator>& rhs);
        
    };


        // Non Member overloads
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
}
#endif