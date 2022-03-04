#include <iostream>
#include <string>
#include "map_reverse_iterator.hpp"
#include "map_iterator.hpp"
#include "map_iterator_traits.hpp"

namespace ft
{
    template<class _T, class _Compare, class _Alloc>
    class AVL_Treee
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
        public:
            typedef _T                                                          value_type;
            typedef _Compare                                                    value_compare;
            typedef _Alloc                                                      allocator_type;
            
            typedef s_node<_T>                                                  node_type;
            typedef typename _Alloc::template rebind<node_type>::other		    node_allocator;
            typedef typename node_allocator::pointer							pointer;
            typedef typename node_allocator::const_pointer						const_pointer;
            typedef typename node_allocator::reference							reference;
            typedef typename node_allocator::const_reference					    const_reference;            
            
            //typedef ft::biderectional_map_iterator<pointer, value_type>             iterator;
            //typedef ft::biderectional_map_iterator<const pointer, const value_type> const_iterator;
            //typedef ft::reverse_iterator<iterator>                                  reverse_iterator;
            //typedef ft::reverse_iterator<const iterator>                            const_reverse_iterator;
            
            typedef typename allocator_type::size_type                                   size_type;
            typedef typename allocator_type::difference_type                             difference_type;

            AVL_Treee()
            {
                this->_root = NULL;
                this->_size = 0;
            }
            AVL_Treee(const AVL_Treee & instance) : _root(NULL), _size(0)
            {
            }
            const AVL_Treee & operator =(const AVL_Treee & instance)
            {

            }
            ~AVL_Treee()
            {

            }
            node_type * CreateNode(value_type value = 0)
            {
                node_type * node = new node_type(value);
                return node;
            }
            // Operations On a AVL_Treee
            // Insertion
            node_type * insertNode(node_type * Node, value_type content)
            {
                if (Node == NULL)
                    return new node_type(content);
                if (content > Node->content)
                    Node->right = insertNode(Node->right, content);
                else if (content < Node->content)
                    Node->left = insertNode(Node->left, content);
                else
                    return Node;
                
                // update height of this ancestor node
                Node->height = 1 + max(getHeight(Node->left), getHeight(Node->right));

             // Left Left Case
                if (Node->balanceFactor > 1 && content < Node->left->content)
                    return LeftLeftRotate(Node);
                
                // Right Right Case
                if (Node->balanceFactor < -1 && content > Node->right->content)
                    return RightRightRotate(Node);
              // Left Right Case 
                if (Node->balanceFactor > 1 && content > Node->left->content)
                    return LeftRightRotate(Node);
                // Right Left Case
                if (Node->balanceFactor < -1 && content < Node->right->content)
                    return RightLeftRotate(Node);
                return Node;
            }
            // Deletion                                    
            node_type * deleteNode(node_type * Node, value_type content)
            {
                if (Node == NULL)
                    return Node;
                if (content < Node->content)
                    deleteNode(Node->left, content);
                else if (content > Node->content)
                    deleteNode(Node->right, content);
                else
                {
                    if (Node->left == NULL || Node->right == NULL)
                        ;
                    
                }
                return Node;
            }
            // Search
            node_type* SearchKey(node_type * root, value_type content);
            // Rotation
                // rotate content roted with y
            node_type * RightRotate(node_type * y)      // i can update balance factor after every movement
            {
                node_type * x = y->left;
                node_type * tmp = x->right;

                // perform rotation
                x->right = y;
                y->left = tmp;

                // update heights
                y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
                x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

                // i can update balance factor after every movement
                y->balanceFactor = getBalanceFactor(y);
                x->balanceFactor = getBalanceFactor(x);

                // return new root
                return x;
            }
                // rotate content roted with x
            node_type * LeftRotate(node_type * x) 
            {
                node_type * y = x->right;
                node_type * tmp = y->left;

                // perform rotation
                y->left = x;
                x->right = tmp;

                // update heights
                x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
                y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
                
                // i can update balance factor after every movement
                x->balanceFactor = getBalanceFactor(x);
                y->balanceFactor = getBalanceFactor(y);
                
                return y;
            }
                // right rotate 
            node_type * LeftLeftRotate(node_type *Node)
            {
                return (RightRotate(Node));
            }
                // left rotate then right rotate
            node_type * LeftRightRotate(node_type *Node)
            {
                Node->left = LeftRotate(Node);
                return (RightRotate(Node));
            }
                // left rotate
            node_type * RightRightRotate(node_type *Node)
            {
                return (LeftRotate(Node));
            }
                // right rotate then left rotate
            node_type * RightLeftRotate(node_type *Node)
            {
                Node->right = RightRotate(Node);
                return (LeftRotate(Node));
            }
                //
            void printInOrder(node_type * root) const
            {
                if (root != NULL)
                {
                    printInOrder(root->left);
                    std::cout << root->content << " ";
                    printInOrder(root->right);
                }
            }
                //
            value_type max(value_type a, value_type b) const
            { 
                return (a > b) ? a : b;
            }
                // ----------------------------------------------------------------//
            int getBalanceFactor(node_type * Node) const
            {
                if (Node == NULL)
                    return 0;
                return (getHeight(Node->left) - getHeight(Node->right));
            }
                //
            int         getHeight(node_type * Node) const
            {
                if (Node == NULL)
                    return 0;
                return (Node->height);
            }
                //
            node_type *    getMinValueNode(node_type * Node) const
            {
                if (Node == NULL)
                    return Node;
                else
                {
                    node_type * min_node; 
                    min_node = Node;
                    
                    while (min_node && min_node->left != NULL)
                        min_node = min_node->left;

                    return min_node;
                }
            }
            s_node<_T> *        _root;
        private:
            int                 _size; // allocator_type::size_type size_type
            allocator_type      _alloc;
            node_allocator      _node_alloc;
    };
}