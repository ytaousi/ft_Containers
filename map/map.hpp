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
                return comp(x.first, y.first);
            }
        public:
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
            
            explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), _Comp(comp)
            {}
            
            template <class InputIterator>
            map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
            {
                _alloc = alloc;
                _Comp = comp;
                // insert elements using iterator's // u can use insert function
            }
            
            map(const map& object)
            {
                *this = object;
            }

                // Destructor
            ~map()
            {
                // AVL_Tree class fucntion to free the tree hold by the map
                // dealocate tree use clear ?
            }
                // Assignement Operator
            map& operator= (const map& object)
            {
                // deallocate old tree use clear;
                _Comp = objec._Comp;
                _alloc = object._alloc;
                // assign element of object tree to this object tree using insert !??
                return *this;
            }
                // Iterator functions
            iterator begin()
            {
                return _NotReadBlackTree.begin();
            }
            const_iterator begin() const
            {
                return _NotReadBlackTree.begin();
            }
            iterator end()
            {
                return _NotReadBlackTree.end();
            }
            const_iterator end() const
            {
                return _NotReadBlackTree.end();
            }
            reverse_iterator rbegin()
            {
                return _NotReadBlackTree.rbegin();
            }
            const_reverse_iterator rbegin() const
            {
                return _NotReadBlackTree.rbegin();
            }
            reverse_iterator rend()
            {
                return _NotReadBlackTree.rend();
            }
            const_reverse_iterator rend() const
            {
                return _NotReadBlackTree.rend();
            }

            // Capacity
            bool empty() const
            {
                return _NotReadBlackTree.empty();
            }
            size_type size() const
            {
                return _NotReadBlackTree.size();
            }
            size_type max_size() const
            {
                return _NotReadBlackTree.max_size();
            }
            // element access is
            mapped_type& operator[] (const key_type& k)
            {
                return _NotReadBlackTree[k];
            }
            // element Modifiers
                // 
            pair<iterator,bool> insert (const value_type& val)
            {
                return insert(val);
            }
            iterator insert (iterator position, const value_type& val)
            {
                return _NotReadBlackTree.insert(position, val);
            }
            template <class InputIterator>
            void insert (InputIterator first, InputIterator last)
            {
                _NotReadBlackTree.insert(first, last);
            }
                // 
            void erase (iterator position)
            {
                _NotReadBlackTree.erase(position);
            }
            size_type erase (const key_type& k)
            {
                return _NotReadBlackTree.erase(k);
            }
            void erase (iterator first, iterator last)
            {
                _NotReadBlackTree.erase(first, last);
            }
                //
            void swap (map& x)
            {
                
            }
                //
            void clear()
            {
                _NotReadBlackTree.clear();
            }
                // Observers functions
            key_compare key_comp() const
            {
                return (key_compare(key_type)); // not sure if correct
            }
            value_compare value_comp() const
            {
                return (value_compare(value_type)); // not sure if correct
            }
                // Operations functions
                // 
            iterator find (const key_type& k)
            {
                return _NotReadBlackTree.find(k);
            }
            const_iterator find (const key_type& k) const
            {
                return _NotReadBlackTree.find(k);
            }
                //
            size_type count (const key_type& k) const
            {
                return _NotReadBlackTree.count(k);
            }
                // 
            iterator lower_bound (const key_type& k)
            {
                return _NotReadBlackTree.lower_bound(k);
            }
            const_iterator lower_bound (const key_type& k) const
            {
                return _NotReadBlackTree.lower_bound(k);
            }
                //
            iterator upper_bound (const key_type& k)
            {
                return _NotReadBlackTree.upper_bound(k);
            }
            const_iterator upper_bound (const key_type& k) const
            {
                return _NotReadBlackTree.upper_bound(k);
            }
                //
            pair<iterator,iterator>             equal_range (const key_type& k)
            {
                return _NotReadBlackTree.equal_range(k);
            }
            pair<const_iterator,const_iterator> equal_range (const key_type& k) const
            {
                return _NotReadBlackTree.equal_range(k); // get return of pair<iterator, iterator> then return const iterators cast maybe !?
            }
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
            //AVL_Tree<value_type, value_compare, allocator_type>   _NotReadBlackTree;
            AVL_Tree                                                _NotReadBlackTree;
            value_compare                                           _Comp;
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