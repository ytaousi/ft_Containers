#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP

# include <iterator>
#include "map_iterator_traits.hpp"
#include "map_iterator.hpp"
#include "pair.hpp"
#include "tree.hpp"

namespace ft
{   //template <class T, class Compare>
    class biderectional_map_iterator : public ft::Iterator<std::bidirectional_iterator_tag, T>
    {
        public:
            typedef typename ft::Iterator<std::bidirectional_iterator_tag, T>::value_type        value_type;
            typedef typename ft::Iterator<std::bidirectional_iterator_tag, T>::difference_type   difference_type;
            typedef typename ft::Iterator<std::bidirectional_iterator_tag, T>::pointer           pointer;
            typedef typename ft::Iterator<std::bidirectional_iterator_tag, T>::reference         reference;
            typedef typename ft::Iterator<std::bidirectional_iterator_tag, T>::iterator_category iterator_category;
            typedef typename ft::s_node<value_type, Compare>                                      node_type;
            
            biderectional_map_iterator()
            {

            }
            biderectional_map_iterator(node_type *Node) : map_iter(Node)
            {
                //end = 0
                //rend = 0;
            }

            biderectional_map_iterator(const biderectional_map_iterator<value_type, Compare> & instance) : map_iter(instance.map_iter)
            {
                //end = instance.end
                //rend = instance.rend
            }
            
            ~biderectional_map_iterator(){};
            biderectional_map_iterator & operator = (const biderectional_map_iterator<value_type, Compare> & instance)
            {
                biderectional_map_iterator temp = instance;

                map_iter = instance.map_iter;
                //end = instance.end;
                //rend = instance.rend;
                return *this;
            }

            // operator biderectional_map_iterator<const T> () const
            // {
            //     return biderectional_map_iterator<const T>(map_iter);
            // }
            
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
                biderectional_map_iterator temp = *this;
                operator ++ ();
                return temp;
            }

            biderectional_map_iterator & operator -- ()
            {
                
            }

            biderectional_map_iterator operator -- (int)
            {
                biderectional_map_iterator temp = *this;
                operator -- ();
                return temp;
            }

            template <class TT>
            friend bool operator == (const biderectional_map_iterator<TT>& lhs, const biderectional_map_iterator<TT>& rhs);
                template <class TT>
            friend bool operator != (const biderectional_map_iterator<TT>& lhs, const biderectional_map_iterator<TT>& rhs);


            private:
            node_type * map_iter;
            //end
            //rend
    };

    template <class T>
    bool operator == (const biderectional_map_iterator<T, Compare>& lhs, const biderectional_map_iterator<T, Compare>& rhs)
    {
        return (lhs.base() == rhs.base());
    }

    template <class T>
    bool operator != (const biderectional_map_iterator<T, Compare>& lhs, const biderectional_map_iterator<T, Compare>& rhs)
    {
        return (lhs.base() != rhs.base());
    }
}

#endif