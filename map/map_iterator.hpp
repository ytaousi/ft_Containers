#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP

# include <iterator>
#include "map_iterator_traits.hpp"

namespace ft
{
    template <class T>
    class biderectional_iterator : public ft::Iterator<std::biderectional_iterator_tag, T>
    {
        public:
            typedef typename ft::Iterator<std::random_access_iterator_tag, T>::value_type        value_type;
            typedef typename ft::Iterator<std::random_access_iterator_tag, T>::difference_type   difference_type;
            typedef typename ft::Iterator<std::random_access_iterator_tag, T>::pointer           pointer;
            typedef typename ft::Iterator<std::random_access_iterator_tag, T>::reference         reference;
            typedef typename ft::Iterator<std::random_access_iterator_tag, T>::iterator_category iterator_category;

            biderectional_iterator() : iter(NULL)
            {

            }
            biderectional_iterator(pointer ptr) : iter(ptr)
            {

            }

            virtual ~biderectional_iterator(){};
            biderectional_iterator(const biderectional_iterator & instance) : iter(instance.base())
            {
                *this = instance;
            }
            biderectional_iterator & operator = (const biderectional_iterator & instance)
            {
                this->iter = instance.base();
                return *this;
            }

            operator biderectional_iterator<const T> () const { return biderectional_iterator<const T>(iter); }
            
            pointer base() const
            {
                return iter;
            }

            reference operator * () const
            {
                return *iter;
            }

            pointer operator -> () const
            {
                //return std::addressof(operator*());
                return &(operator*());
            }

            // pre incremented
            biderectional_iterator & operator ++ ()
            {
                ++(this->iter);
                return *this;
            }
            // post incremented
            biderectional_iterator operator ++ (int)
            {
                biderectional_iterator temp = *this;
                ++(this->iter);
                return temp;
            }

            biderectional_iterator & operator -- ()
            {
                --(this->iter);
                return *this;
            }

            biderectional_iterator operator -- (int)
            {
                biderectional_iterator temp = *this;
                --(this->iter);
                return temp;
            }

            template <class TT>
            friend bool operator == (const biderectional_iterator<TT>& lhs, const biderectional_iterator<TT>& rhs);
                template <class TT>
            friend bool operator != (const biderectional_iterator<TT>& lhs, const biderectional_iterator<TT>& rhs);
    };

    template <class T>
    bool operator == (const biderectional_iterator<T>& lhs, const biderectional_iterator<T>& rhs)
    {
        return (lhs.base() == rhs.base());
    }

    template <class T>
    bool operator != (const biderectional_iterator<T>& lhs, const biderectional_iterator<T>& rhs)
    {
        return (lhs.base() != rhs.base());
    }
}

#endif