#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <iterator>
# include "iterator_traits.hpp"

namespace ft
{
    template <class T>
    class random_access_iterator : public ft::Iterator<std::random_access_iterator_tag, T>
    {
        public:
            typedef typename ft::Iterator<std::random_access_iterator_tag, T>::value_type        value_type;
            typedef typename ft::Iterator<std::random_access_iterator_tag, T>::difference_type   difference_type;
            typedef typename ft::Iterator<std::random_access_iterator_tag, T>::pointer           pointer;
            typedef typename ft::Iterator<std::random_access_iterator_tag, T>::reference         reference;
            typedef typename ft::Iterator<std::random_access_iterator_tag, T>::iterator_category iterator_category;
        
            random_access_iterator();
            ~random_access_iterator();
            random_access_iterator(const random_access_iterator & instance);
            random_access_iterator & operator = (const random_access_iterator & instance);


            pointer base() const
            {

            }

            reference operator * () const
            {

            }

            random_access_iterator operator + (difference_type n) const
            {

            }

            // pre incremented
            random_access_iterator & operator ++ ()
            {

            }
            // post incremented
            random_access_iterator operator ++ (int)
            {

            }

            random_access_iterator & operator += (difference_type n)
            {

            }

            random_access_iterator operator - (difference_type n) const
            {

            }

            random_access_iterator & operator -- ()
            {

            }

            random_access_iterator operator -- (int)
            {

            }

            random_access_iterator & operator -= (difference_type n)
            {

            }

            pointer operator -> () const
            {

            }

            reference operator [] (difference_type n) const
            {

            }

            // friend function for random_access_iterator class
                template <class T>
            friend bool operator == (const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs);
                template <class T>
            friend bool operator != (const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs);
                template <class T>
            friend bool operator < (const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs);
                template <class T>
            friend bool operator <= (const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs);
                template <class T>
            friend bool operator > (const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs);
                template <class T>
            friend bool operator >= (const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs);


        private:
            pointer iter;
    };
        // Non-member funcs

    // addition operator
    template <class T>
    random_access_iterator<T> operator + (typename random_access_iterator<T>::difference_type n, const random_access_iterator<T>& iter)
    {
        return (iter + n);
    }

    // susbstraction operator
    template <class T>
    typename random_access_iterator<T>::difference_type operator - (const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs)
    {
        return (lhs.base() - rhs.base());
    }

    // relational operators
    template <class T>
    bool operator == (const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs)
    {
        return (lhs.base() == rhs.base());
    }

    template <class T>
    bool operator != (const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs)
    {
        return (lhs.base() != rhs.base());
    }

    template <class T>
    bool operator < (const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs)
    {
        return (lhs.base() < rhs.base());
    }

    template <class T>
    bool operator <= (const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs)
    {
        return (lhs.base() <= rhs.base());
    }

    template <class T>
    bool operator > (const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs)
    {
        return (lhs.base() > rhs.base());
    }

    template <class T>
    bool operator >= (const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs)
    {
        return (lhs.base() >= rhs.base());
    }
}

#endif