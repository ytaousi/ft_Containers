#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "iterator.hpp"
# include "iterator_traits.hpp"
# include <memory>
// still need to define the iterator traits template done
// so that typedef's takes in account done
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
            
        // Member Function's

            //return base iterator that was initialized with ??
            iterator_type base() const
            {
                iterator_type tmp = rev_iter;
                return ++tmp; // !!
            }

            //dereference iterator
            reference operator * () const
            {
                iterator_type temp = rev_iter;  // segf found bitch
                return *temp;
            }

            //addition operator
            reverse_iterator operator+ (difference_type n) const
            {
                return reverse_iterator(rev_iter - (n - 1));
            }

            //pre-increment iterator position
            // return the value after incrementation
            reverse_iterator& operator++()
            {
                --(this->rev_iter);
                return (*this);
            }

            //post-incrementation
            // return the value before incrementation
            reverse_iterator operator++(int)
            {
                reverse_iterator temp = *this;
                //--(this->rev_iter);
                ++(*this);
                return temp;
            }

            //advance iterator
            reverse_iterator& operator+= (difference_type n)
            {
                (this->rev_iter) -= n;   // pretty sure frechnaha somewhere                
                return (*this);
            }

            //substraction iterator
            reverse_iterator operator- (difference_type n) const
            {
                return reverse_iterator(rev_iter + (n + 1));
            }

            //pre-decrement iterator position
            reverse_iterator& operator--()
            {
                ++(this->rev_iter);
                return (*this);
            }

            //post-decrementation
            reverse_iterator  operator--(int)
            {
                reverse_iterator temp = *this;
                //--(this->rev_iter);
                --(*this);
                return temp;
            }

            //retrocede iterator
            reverse_iterator& operator-= (difference_type n)
            {
                (this->rev_iter) += n;
                return (*this);   // pretty sure frechnaha somewhere
            }

            //dereference iterator
            pointer operator->() const
            {
                //return std::addressof(operator*());
                return &(operator*());
            }

            //dereference iterator with offset
            reference operator[] (difference_type n) const
            {
                return (rev_iter[-n]);
            }

            // friend function to the class implementation
                template <class IIterator>
            friend bool operator== (const reverse_iterator<IIterator>& lhs, const reverse_iterator<IIterator>& rhs);
                template <class IIterator>
            friend bool operator!= (const reverse_iterator<IIterator>& lhs, const reverse_iterator<IIterator>& rhs);
                template <class IIterator>
            friend bool operator<  (const reverse_iterator<IIterator>& lhs, const reverse_iterator<IIterator>& rhs);
                template <class IIterator>
            friend bool operator<= (const reverse_iterator<IIterator>& lhs, const reverse_iterator<IIterator>& rhs);
                template <class IIterator>
            friend bool operator>  (const reverse_iterator<IIterator>& lhs, const reverse_iterator<IIterator>& rhs);
                template <class IIterator>
            friend bool operator>= (const reverse_iterator<IIterator>& lhs, const reverse_iterator<IIterator>& rhs);

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
        return (rhs.base() - lhs.base());
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
        return (lhs.base() > rhs.base());
    }

    template <class Iterator>
    bool operator<= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base() >= rhs.base());
    }

    template <class Iterator>
    bool operator>  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base() < rhs.base());
    }

    template <class Iterator>
    bool operator>= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base() <= rhs.base());
    }
}
#endif