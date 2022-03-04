#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP

# include <iterator>
#include "map_iterator_traits.hpp"
#include "pair.hpp"
#include "tree.hpp"

namespace ft
{
    template <class T>
    class biderectional_map_iterator : public ft::Iterator<std::biderectional_iterator_tag, T>
    {
        public:
            biderectional_map_iterator() : iter(NULL)
            {

            }
            biderectional_map_iterator(pointer ptr) : iter(ptr)
            {

            }

            virtual ~biderectional_map_iterator(){};
            biderectional_map_iterator(const biderectional_map_iterator & instance) : iter(instance.base())
            {
                *this = instance;
            }
            biderectional_map_iterator & operator = (const biderectional_map_iterator & instance)
            {
                this->iter = instance.base();
                return *this;
            }

            operator biderectional_map_iterator<const T> () const { return biderectional_map_iterator<const T>(iter); }
            
            pointer base() const
            {
                return iter;
            }

            reference operator * () const
            {
                
            }

            pointer operator -> () const
            {
                //return std::addressof(operator*());
                
            }

            // pre incremented
            biderectional_map_iterator & operator ++ ()
            {
                
            }
            // post incremented
            biderectional_map_iterator operator ++ (int)
            {
                
            }

            biderectional_map_iterator & operator -- ()
            {
                
            }

            biderectional_map_iterator operator -- (int)
            {
                
            }

            template <class TT>
            friend bool operator == (const biderectional_map_iterator<TT>& lhs, const biderectional_map_iterator<TT>& rhs);
                template <class TT>
            friend bool operator != (const biderectional_map_iterator<TT>& lhs, const biderectional_map_iterator<TT>& rhs);
    };

    template <class T>
    bool operator == (const biderectional_map_iterator<T>& lhs, const biderectional_map_iterator<T>& rhs)
    {
        return (lhs.base() == rhs.base());
    }

    template <class T>
    bool operator != (const biderectional_map_iterator<T>& lhs, const biderectional_map_iterator<T>& rhs)
    {
        return (lhs.base() != rhs.base());
    }
}

#endif