#ifndef TREE_HPP
#define TREE_HPP

#include <iostream>
#include <string>
#include "map_reverse_iterator.hpp"
#include "map_iterator.hpp"
#include "map_iterator_traits.hpp"
#include <memory>

/*
1. Left Rotation 
        : If the addition of a node to the tree’s right makes it imbalance then, in that case, Left Rotation needs to be performed.
-
2. Right Rotation 
        : If the addition of a node to the left of the tree makes the node imbalance then Right Rotation needs to be performed.
            In other words, When the number of nodes increases on the left side,
                then there emerges a need to shift the elements to the right side to balance it thus it is said to be Right Rotation.
-
3. Left-Right Rotation 
        : This type of rotation is a combination of the above 2 rotations explained.
            This type of rotation occurs when one element is added to the right subtree of a left tree.
-
In such a case first, perform left rotation on the subtree followed by a right rotation of the left tree.
-
4. Right-Left Rotation
        : This type of rotation is also composed of a sequence of above 2 rotations.
            This type of rotation is needed when an element is added to the left of the right subtree,
        and the tree becomes imbalanced. In such a case, we first perform right rotation on the right subtree and then left rotation on the right tree.
*/

/*
Operations On AVL Tree :
1-Search
-
2-Insertion
-
3-deletion
*/
namespace ft
{
    //template<class _T, class _Compare, class _Alloc>
    class AVL_Tree
    {
        public:
            //template<typename T>
            struct  s_node
            {
                public:                                       // pair<key, value>
                    int                 key;   // T will be typedefed as value_type
                    s_node *            left;
                    s_node *            right;
                    s_node *            parent; // predecessor node
                    //struct s_node *     child; // descendent
                    int                 height;
                    int                 balanceFactor;

                    s_node(int key = 0)
                    {
                        this->key = key;
                        this->left = NULL;
                        this->right = NULL;
                        this->parent = NULL;
                        this->height = 1;
                        this->balanceFactor = 0;
                    }
                    s_node(const s_node * instance)
                    {
                        this->key = instance->key;
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
            int                 _size;
        public:
        typedef struct s_node t_node;
            t_node *            root;
            AVL_Tree()
            {
                //std::cout << "Empty tree only one node with no data" << std::endl;
                this->root = NULL;
                this->_size = 0;
            }
            AVL_Tree(const AVL_Tree & instance) : root(NULL), _size(0)
            {
                *this = instance;
            }
            const AVL_Tree & operator = (const AVL_Tree & instance)
            {
                this->_size = instance._size;
                this->root = instance.root;
                return *this;
            }
            ~AVL_Tree()
            {
                //std::cout << "Tree destructor Called" << std::endl;
                if (root != NULL)
                    delete root;
            }
            t_node * CreateNode(int value = 0)
            {
                t_node * node = new t_node(value);
                return node;
            }
            // Operations On a AVL_Tree
            // Insertion
            t_node * insertNode(t_node * Node, int key)
            {
                if (Node == NULL)
                    return new t_node(key);
                if (key > Node->key)
                    Node->right = insertNode(Node->right, key);
                else if (key < Node->key)
                    Node->left = insertNode(Node->left, key);
                else
                    return Node;
                
                // update height of this ancestor node
                Node->height = 1 + max(getHeight(Node->left), getHeight(Node->right));

             // Left Left Case
                if (Node->balanceFactor > 1 && key < Node->left->key)
                    return LeftLeftRotate(Node);
                
                // Right Right Case
                if (Node->balanceFactor < -1 && key > Node->right->key)
                    return RightRightRotate(Node);
              // Left Right Case 
                if (Node->balanceFactor > 1 && key > Node->left->key)
                    return LeftRightRotate(Node);
                // Right Left Case
                if (Node->balanceFactor < -1 && key < Node->right->key)
                    return RightLeftRotate(Node);
                return Node;
            }
            // Deletion     Not Working                               
            t_node * deleteNode(t_node * Node, int key)
            {
                t_node * p;
                if (Node == NULL)
                    return Node;
                if (k > Node->key)
                {
                    Node = deleteNode(Node->right, key);
                    // update balance factor
                    if (getBalanceFactor(Node) == 2)
                        // fix rotation
                }
                else
                {

                    if (k < Node->key)
                    {
                        Node = deleteNode(Node->left, key);
                        // update balance factor
                        if (getBalanceFactor(Node) == -2)
                            // fix rotation
                    }
                    else
                    {
                        if (Node->right != NULL)
                        {
                            p = Node->right;

                            while(p->left != NULL)
                                p = p->left;

                            Node->key = p->key;
                            Node->right = deleteNode(Node->right, p->key);
                            // update balance factor
                            if(balanceFactor(T) == 2)
                                // fix rotation
                        }
                        else
                            return Node->left;
                    }
                }
                Node->height = max(getHeight(Node->left) - getHeight(Node->right));
                return Node;
            }
            // Search
            t_node* SearchKey(t_node * Node, int key)
            {
                if (Node == NULL || Node->key == key)
                    return Node;
                if (key < Node->key)
                    return SearchKey(Node->left, key);
                if (key > Node->key)
                    return SearchKey(Node->right, key);
                return Node;
            }
            // Rotation
                // rotate key roted with y
            t_node * RightRotate(t_node * y)      // i can update balance factor after every movement
            {
                t_node * x = y->left;
                t_node * tmp = x->right;

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
                // rotate key roted with x
            t_node * LeftRotate(t_node * x) 
            {
                t_node * y = x->right;
                t_node * tmp = y->left;

                // perform rotation
                y->left = x;
                x->right = tmp;

                // update heights
                x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
                y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
                
                // i can update balance factor after every movement
                x->balanceFactor = getBalanceFactor(x);
                y->balanceFactor = getBalanceFactor(y);
                
                
                // return new root
                return y;
            }
                // right rotate 
            t_node * LeftLeftRotate(t_node *Node)
            {
                return (RightRotate(Node));
            }
                // left rotate then right rotate
            t_node * LeftRightRotate(t_node *Node)
            {
                Node->left = LeftRotate(Node);
                return (RightRotate(Node));
            }
                // left rotate
            t_node * RightRightRotate(t_node *Node)
            {
                return (LeftRotate(Node));
            }
                // right rotate then left rotate
            t_node * RightLeftRotate(t_node *Node)
            {
                Node->right = RightRotate(Node);
                return (LeftRotate(Node));
            }

                // Print Tree
                    // types of traversal
                        // PreOrder traversal
                        // PostOrder traversal
                // - InOrder traversal
            void printInOrder(t_node * root) const
            {
                if (root != NULL)
                {
                    printInOrder(root->left);
                    std::cout << root->key << " ";
                    printInOrder(root->right);
                }
            }
            int max(int a, int b) const
            { 
                return (a > b) ? a : b;
            }
                // factor of balance should be -1 0 +1 :  height(left-subtree)-height(right-subtree)
            int getBalanceFactor(t_node * Node) const
            {
                if (Node == NULL)
                    return 0;
                return (getHeight(Node->left) - getHeight(Node->right));
            }
                
                //
            int         getHeight(t_node * Node) const
            {
                if (Node == NULL)
                    return 0;
                return (Node->height);
            }
                //
            t_node *    getMinValueNode(t_node * Node) const
            {
                if (Node == NULL)
                    return Node;
                else
                {
                    t_node * min_node; 
                    min_node = Node;
                    
                    while (min_node && min_node->left != NULL)
                        min_node = min_node->left;

                    return min_node;
                }
            }

        /*----------------------------------------------------------*/
        /*----------------------------------------------------------*/
        // iterator functions
        iterator begin();
        const_iterator begin() const;
        iterator end();
        const_iterator end() const;
        reverse_iterator rbegin();
        const_reverse_iterator rbegin() const;
        const_reverse_iterator rend() const;
        /*----------------------------------------------------------*/
        /*----------------------------------------------------------*/
        // element modifier functions
        value_type insert(const value_type& value);  // u need to check template parameter values
        iterator insert(iterator position, const value_type value);
            template<class InputIterator>
        void insert(InputIterator first, InputIterator last);
        void erase(iterator position);
        size_type erase(const key_type& k);
        void erase(iterator first. iterator last);
        void clear();
        /*----------------------------------------------------------*/
        /*----------------------------------------------------------*/
        // Operations functions
        iterator find(const key_type& k);
        const_iterator find(const key_type& k) const;
        size_type count(const key_type& k) const;
        iterator lower_bound(const key_type& k);
        const_iterator lower_bound(const key_type& k) const;
        iterator upper_bound(const key_type& k);
        const_iterator upper_bound(const key_type& k) const;
        value_type equal_range(const key_type& k);
        const value_type equal_range(const key_type& k) const;
        /*----------------------------------------------------------*/
        /*----------------------------------------------------------*/
        bool empty() const;
        size_type size() const;
        size_type max_size() const;

    };
/*                                                      
         z                                      y 
        / \                                   /   \
       y   T4      Right Rotate (z)          x      z
      / \          - - - - - - - - ->      /  \    /  \ 
     x   T3                               T1  T2  T3  T4
    / \
  T1   T2
*/

/*
                    z                               y
                   /  \                            / \ 
                  T1   y      Left Rotate(z)      z    x
                      /  \    - - - - - - - ->   / \   / \
                     T2   x                     T1 T2 T3  T4
                        / \
                       T3  T4
*/

/*
        z                               z                         x
       / \                            /   \                      /  \ 
      y   T4   Left Rotate (y)       x    T4  Right Rotate(z)   y    z
     / \       - - - - - - - - ->   / \      - - - - - - - ->  / \   / \
    T1  x                          y   T3                    T1  T2 T3 T4
        / \                       / \
       T2  T3                    T1  T2
*/

/*
            z                             z                            x
            / \                          / \                          /  \ 
           T1   y   Right Rotate (y)    T1  x      Left Rotate(z)    z     y
               / \  - - - - - - - - ->     /  \   - - - - - - - ->  / \   / \
              x   T4                      T2   y                  T1  T2 T3 T4
             / \                              /  \
            T2  T3                           T3   T4
*/
            /*     
                following order  : keys(T1) < key(x) < keys(T2) < key(y) < keys(T3)
                So BinarySearchTree property is not violated anywhere.
                
                -AVL trees follow all properties of Binary Search Trees.
                -The left subtree has nodes that are lesser than the root node. The right subtree has nodes that are always greater than the root node.
                -AVL trees are self-balancing binary search trees.
                -The insert and delete operation require rotations to be performed after violating the balance factor.
                -The time complexity of insert, delete, and search operation is O(log N).
            
            */

            // Why AVL and not RBL Tree , well because i am lazy ok!! RTFM
            /* ---------------------------------------------------------------- /
                The AVL trees are more balanced compared to Red-Black Trees,
                but they may cause more rotations during insertion and deletion.
                So if your application involves frequent insertions and deletions,
                then Red-Black trees should be preferred. And if the insertions and deletions are less frequent and search is a more frequent operation,
                then AVL tree should be preferred over Red-Black Tree 
            */
}

#endif