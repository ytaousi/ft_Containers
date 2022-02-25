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
        
            random_access_iterator() : iter(NULL)
            {

            }
            random_access_iterator(pointer ptr) : iter(ptr)
            {

            }

            virtual ~random_access_iterator(){};
            random_access_iterator(const random_access_iterator & instance) : iter(instance.base())
            {
                *this = instance;
            }
            random_access_iterator & operator = (const random_access_iterator & instance)
            {
                this->iter = instance.base();
                return *this;
            }

            operator random_access_iterator<const T> () const { return random_access_iterator<const T>(iter); }
            pointer base() const
            {
                return iter;
            }

            reference operator * () const
            {
                return *iter;
            }

            random_access_iterator operator + (difference_type n) const
            {
                return random_access_iterator(this->base() + n);
            }

            // pre incremented
            random_access_iterator & operator ++ ()
            {
                ++(*this);
                return *this;
            }
            // post incremented
            random_access_iterator operator ++ (int)
            {
                random_access_iterator temp = *this;
                ++(*this);
                return temp;
            }

            random_access_iterator & operator += (difference_type n)
            {
                (*this) += n;
                return (*this);
            }

            random_access_iterator operator - (difference_type n) const
            {
                return random_access_iterator(this->base() - n);
            }

            random_access_iterator & operator -- ()
            {
                --(*this);
                return *this;
            }

            random_access_iterator operator -- (int)
            {
                random_access_iterator temp = *this;
                --(*this);
                return temp;
            }

            random_access_iterator & operator -= (difference_type n)
            {
                (*this) -= n;
                return (*this);
            }

            pointer operator -> () const
            {
                //return std::addressof(operator*());
                return &(operator*());
            }

            reference operator [] (difference_type n) const
            {
                return (base()[+n]);
            }

            // friend function for random_access_iterator class
                template <class TT>
            friend bool operator == (const random_access_iterator<TT>& lhs, const random_access_iterator<TT>& rhs);
                template <class TT>
            friend bool operator != (const random_access_iterator<TT>& lhs, const random_access_iterator<TT>& rhs);
                template <class TT>
            friend bool operator < (const random_access_iterator<TT>& lhs, const random_access_iterator<TT>& rhs);
                template <class TT>
            friend bool operator <= (const random_access_iterator<TT>& lhs, const random_access_iterator<TT>& rhs);
                template <class TT>
            friend bool operator > (const random_access_iterator<TT>& lhs, const random_access_iterator<TT>& rhs);
                template <class TT>
            friend bool operator >= (const random_access_iterator<TT>& lhs, const random_access_iterator<TT>& rhs);

                template <class TT>
            friend random_access_iterator<TT> operator + (typename random_access_iterator<TT>::difference_type n, const random_access_iterator<TT>& iter);
                template <class TT>
            friend typename random_access_iterator<TT>::difference_type operator - (const random_access_iterator<TT>& lhs, const random_access_iterator<TT>& rhs);

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