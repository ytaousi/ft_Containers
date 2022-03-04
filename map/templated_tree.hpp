#include <iostream>
#include <string>
#include "map_reverse_iterator.hpp"
#include "map_iterator.hpp"
#include "map_iterator_traits.hpp"

namespace ft
{
    template<class _T, class _Compare, class _Alloc>
    class AVL_Tree
    {
        public:
            template<typename T>
            struct  s_node
            {
                public:
                    typedef T               value_type;                           // pair<key, value>
                    
                    value_type          content;   // T will be typedefed as value_type
                    s_node *            left;
                    s_node *            right;
                    s_node *            parent; // predecessor node
                    //struct s_node *     child; // descendent
                    int                 height;
                    int                 balanceFactor;

                    s_node(T content)
                    {
                        this->content = content;
                        this->left = NULL;
                        this->right = NULL;
                        this->parent = NULL;
                        this->height = 1;
                        this->balanceFactor = 0;
                    }
                    s_node(const s_node * instance)
                    {
                        this->content = instance->content;
                        this->left = instance->left;
                        this->right = instance->right;
                        this->parent = instance->parent;
                        this->height = instance->height;
                        this->balanceFactor = instance->balanceFactor;
                    }
                    ~s_node()
                    {}
            };
      
        private:
            int                 _size; // allocator_type::size_type size_type
        public:
            typedef _T                                                          value_type;
            typedef _Compare                                                    value_compare;
            typedef _Alloc                                                      allocator_type;
            
            typedef ft::s_node<_T>                                              node_type;
            typedef typename _Alloc::template rebind<node_type>::other		    node_allocator;
            typedef typename node_allocator::pointer							pointer;
            typedef typename node_allocator::const_pointer						const_pointer;
            typedef typename node_allocator::reference							reference;
            typedef typename node_allocator::const_reference					    const_reference;            
            
            typedef ft::biderectional_map_iterator<pointer, value_type>             iterator;
            typedef ft::biderectional_map_iterator<const pointer, const value_type> const_iterator;
            typedef ft::reverse_iterator<iterator>                                  reverse_iterator;
            typedef ft::reverse_iterator<const iterator>                            const_reverse_iterator;
            
            typedef allocator_type::size_type                                   size_type;
            typedef allocator_type::difference_type                             difference_type;
        
        

    };

}