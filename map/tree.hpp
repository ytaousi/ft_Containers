#ifndef TREE_HPP
#define TREE_HPP

#include <iostream>
#include <string>
    // 

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
    class AVL_Tree
    {
        public:
            struct  s_node
            {
                public:
                    int                 key;      // pair<key, value>
                    struct s_node *     left;
                    struct s_node *     right;
                    struct s_node *     parent; // predecessor node
                    //struct s_node *     child; // successor node
                    int                 height;
                    int                 balanceFactor;

                    s_node(int key = 0)
                    {
                        //std::cout << "struct Node Constructor Called" << std::endl;
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

                        // Assignement operator overload on struct !!?
                    //

                    ~s_node()
                    {
                        //std::cout << "struct Node Destructor Called" << std::endl;
                        if (this->left)
                            delete left;
                        if (this->right)
                            delete right;
                        if (this->parent)
                            delete parent;
                    }
            };
        private:
            int                 _size;
        // Properties Of Binary tree  ( max nodes using level : 2^l / max node using height : 2^height - 1/ 
        //                            / minimum possible height or minimum possible level with N Nodes : Log2(N+1)
        
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

                
/*                                                      
         z                                      y 
        / \                                   /   \
       y   T4      Right Rotate (z)          x      z
      / \          - - - - - - - - ->      /  \    /  \ 
     x   T3                               T1  T2  T3  T4
    / \
  T1   T2
*/             // Left Left Case
                if (Node->balanceFactor > 1 && key < Node->left->key)
                    return LeftLeftRotate(Node);
                
                
/*
                    z                               y
                   /  \                            / \ 
                  T1   y      Left Rotate(z)      z    x
                      /  \    - - - - - - - ->   / \   / \
                     T2   x                     T1 T2 T3  T4
                        / \
                       T3  T4
*/              // Right Right Case
                if (Node->balanceFactor < -1 && key > Node->right->key)
                    return RightRightRotate(Node);
/*
        z                               z                         x
       / \                            /   \                      /  \ 
      y   T4   Left Rotate (y)       x    T4  Right Rotate(z)   y    z
     / \       - - - - - - - - ->   / \      - - - - - - - ->  / \   / \
    T1  x                          y   T3                    T1  T2 T3 T4
        / \                       / \
       T2  T3                    T1  T2
*/              // Left Right Case 
                if (Node->balanceFactor > 1 && key > Node->left->key)
                    return LeftRightRotate(Node);
/*
            z                             z                            x
            / \                          / \                          /  \ 
           T1   y   Right Rotate (y)    T1  x      Left Rotate(z)    z     y
               / \  - - - - - - - - ->     /  \   - - - - - - - ->  / \   / \
              x   T4                      T2   y                  T1  T2 T3 T4
             / \                              /  \
            T2  T3                           T3   T4
*/                // Right Left Case
                if (Node->balanceFactor < -1 && key < Node->right->key)
                    return RightLeftRotate(Node);
                return Node;
            }
            // Deletion                                    
            t_node * deleteNode(t_node * Node, int key);
            // Search
            t_node* SearchKey(t_node * root, int key);
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
                // - inerdor traversal
            void printInOrder(t_node * root) const
            {
                if (root != NULL)
                {
                    printInOrder(root->left);
                    std::cout << root->key << " ";
                    printInOrder(root->right);
                }
            }
                // - preorder traversal 
            // void printPreOrder(t_node * root) const
            // {
            //     if (root != NULL)
            //     {
            //         std::cout << root->key << " ";
            //         printPreOrder(root->left);
            //         printPreOrder(root->right);
            //     }
            // }
                // - postorder traversal
            // void printPostOrder(t_node * root) const
            // {
            //     if (root != NULL)
            //     {
            //         printPostOrder(root->left);
            //         printPostOrder(root->right);
            //         std::cout << root->key << " ";
            //     }
            // }

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
            t_node *    getMinValueNode(t_node * Node) const;
                //
    };

            /*
                y                                x
               / \       Right Rotation         / \
              x   T3     - - - - - - - >       T1  y 
             / \         < - - - - - - -          / \
            T1  T2       Left Rotation          T2  T3
        
                following order  : keys(T1) < key(x) < keys(T2) < key(y) < keys(T3)
                So BinarySearchTree property is not violated anywhere.
                
                -AVL trees follow all properties of Binary Search Trees.
                -The left subtree has nodes that are lesser than the root node. The right subtree has nodes that are always greater than the root node.
                -AVL trees are self-balancing binary search trees.
                -The insert and delete operation require rotations to be performed after violating the balance factor.
                -The time complexity of insert, delete, and search operation is O(log N).
            
            */
}

#endif