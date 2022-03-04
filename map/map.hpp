#ifndef MAP_HPP
# define MAP_HPP

# include "pair.hpp"
# include <memory>
# include "map_reverse_iterator.hpp"
# include "map_iterator.hpp"
# include "map_iterator_traits.hpp"
# include <functional>
# include "tree.hpp"

namespace ft
{

    template <class value_type>
    class value_compare : public std::binary_function<value_type,value_type>,bool> // !! use it as the value_compare object of type value_type
    {
        public:
            typedef value_type  first_argument_type;
            typedef value_type  second_argument_type;
            typedef bool        result_type;

            bool operator() (const first_argument_type& x, const second_argument_type& y) const
            {
                return x < y;
            }
        protected:
            Compare comp;
            value_compare (Compare c) : comp(c) {}
    };

    template < class Key, class T, class Compare = std::less<Key>, class
                    Alloc = std::allocator<ft::pair<const Key,T> > >
    class map
    {
        public: 
            typedef Key                                                                             key_type;
            typedef T                                                                               mapped_type;
            typedef ft::pair<const key_type, mapped_type>                                           value_type;
            typedef Compare                                                                         key_compare;
            // dont know if correct typedef for class value_compare // done
            typedef ft::value_compare<value_type>                                                   value_compare;
            typedef typename allocator_type::reference                                              reference;
            typedef typename allocator_type::const_reference                                        const_reference;
            typedef typename allocator_type::pointer                                                pointer;
            typedef typename allocator_type::const_pointer                                          const_pointer;
            typedef ft::biderectional_map_iterator<value_type>                                      iterator;
            typedef ft::biderectional_map_iterator<const value_type>                                const_iterator;
            typedef ft::reverse_iterator<iterator>                                                  reverse_iterator;
            typedef ft::reverse_iterator<const iterator>                                            const_reverse_iterator;
            typedef ptrdiff_t                                                                       difference_type;
            typedef size_t                                                                          size_type;
            typedef Alloc                                                                           allocator_type;
        

                // Constructors
            
            explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
            {}
            
            template <class InputIterator>
            map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
            {}
            
            map(const map& object)
            {}

                // Destructor
            ~map()
            {}
                // Assignement Operator
            map& operator= (const map& x)
            {}
                // Iterator functions
            iterator begin()
            {}
            const_iterator begin() const
            {}
            iterator end()
            {}
            const_iterator end() const
            {}
            reverse_iterator rbegin()
            {}
            const_reverse_iterator rbegin() const
            {}
            reverse_iterator rend()
            {}
            const_reverse_iterator rend() const
            {}

            // Capacity
            bool empty() const
            {
                return (begin() == end());
            }
            size_type size() const
            {
                return (std::distance(begin(), end()));
                // return (_size);
            }
            size_type max_size() const
            {
                return (_alloc.max_size());
            }
            // element access is
            mapped_type& operator[] (const key_type& k)
            {}
            // element Modifiers
                // 
            pair<iterator,bool> insert (const value_type& val)
            {}
            iterator insert (iterator position, const value_type& val)
            {}
            template <class InputIterator>
            void insert (InputIterator first, InputIterator last)
            {}
                // 
            void erase (iterator position)
            {} 
            size_type erase (const key_type& k)
            {}
            void erase (iterator first, iterator last)
            {}
                //
            void swap (map& x)
            {}
                //
            void clear()
            {}
                // Observers functions
            key_compare key_comp() const
            {
                return (_Comp);
            }
            value_compare value_comp() const
            {}
                // Operations functions

                // 
            iterator find (const key_type& k)
            {}
            const_iterator find (const key_type& k) const
            {}
                //
            size_type count (const key_type& k) const
            {}
                // 
            iterator lower_bound (const key_type& k)
            {}
            const_iterator lower_bound (const key_type& k) const
            {}
                //
            iterator upper_bound (const key_type& k)
            {}
            const_iterator upper_bound (const key_type& k) const
            {}
                //
            pair<iterator,iterator>             equal_range (const key_type& k)
            {}
            pair<const_iterator,const_iterator> equal_range (const key_type& k) const
            {}
                // get_allocator
            allocator_type get_allocator () const
            {
                return (_alloc);
            }

                template <class KKey, class TT>
            friend bool operator== ( const map<KKey,TT>& lhs, const map<KKey,TT>& rhs );
                template <class KKey, class TT>
            friend bool operator!= ( const map<KKey,TT>& lhs, const map<KKey,TT>& rhs );
                template <class KKey, class TT>
            friend bool operator<  ( const map<KKey,TT>& lhs, const map<KKey,TT>& rhs );
                template <class KKey, class TT>
            friend bool operator<= ( const map<KKey,TT>& lhs, const map<KKey,TT>& rhs );
                template <class KKey, class TT>
            friend bool operator>  ( const map<KKey,TT>& lhs, const map<KKey,TT>& rhs );
                template <class KKey, class TT>
            friend bool operator>= ( const map<KKey,TT>& lhs, const map<KKey,TT>& rhs );
        
                template <class KKey, class TT>
            friend void swap (map<KKey,TT>& x, map<KKey,TT>& y);
        
        private:
            allocator_type                                          _alloc;
            //AVL_Tree<value_type, key_compare, allocator_type>        _NotReadBlackTree;
            AVL_Tree                                                _NotReadBlackTree;
            key_compare                                             _Comp;

            
    };
        template <class Key, class T>
    bool operator== ( const map<Key,T>& lhs, const map<Key,T>& rhs )
    {}
        template <class Key, class T>
    bool operator!= ( const map<Key,T>& lhs, const map<Key,T>& rhs )
    {}
        template <class Key, class T>
    bool operator<  ( const map<Key,T>& lhs, const map<Key,T>& rhs )
    {}
        template <class Key, class T>
    bool operator<= ( const map<Key,T>& lhs, const map<Key,T>& rhs )
    {}
        template <class Key, class T>
    bool operator>  ( const map<Key,T>& lhs, const map<Key,T>& rhs )
    {}
        template <class Key, class T>
    bool operator>= ( const map<Key,T>& lhs, const map<Key,T>& rhs )
    {}

        template <class Key, class T>
    void swap (map<Key,T>& x, map<Key,T>& y)
    {
        x.swap(y);
    }
}
#endif