#ifndef TREE_HPP
#define TREE_HPP

#include <iostream>

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
    typedef struct  s_node
    {
        int                 key;      // pair<key, value>
        struct s_node *     left;
        struct s_node *     right;
        struct s_node *     parent;
        int                 height;
        int                 balanceFactor;
    }               t_node;

    class AVL_Tree
    {
        private:
            t_node *            root;
            int                 _size;
            int                 _height;
            int                 _balance_factor; // balancing happen when balance factor does not satisfy <=1 condition     
                                            //" (-1 <= Balance Factor >= 1) = height(left-subtree) − height(right-subtree) "   correct balance factor is 1, 0 and -1.
        
        // Properties Of Binary tree  ( max nodes using level : 2^l / max node using height : 2^height - 1/ 
        //                            / minimum possible height or minimum possible level with N Nodes : Log2(N+1)
        
        public:
            AVL_Tree() : root(NULL), _size(0), _height(0), _balance_factor(0)
            {
                std::cout << "Empty tree only one node with no data" << std::endl;

                root = CreateNode();
            }
            ~AVL_Tree()
            {
                std::cout << "Tree destructor Called" << std::endl;
                delete root; 
            }

            const t_node & getNode() const
            {
                return *root;
            }

            t_node * CreateNode(int value = 0)
            {
                t_node * node = new t_node();
                node->key = value;
                node->height = 1;
                node->left = NULL;
                node->right = NULL;
                node->parent = NULL;
                node->balanceFactor = 0;
                return node;
            }
        // Operations On a AVL_Tree
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

            // Insertion
            t_node * insertNode(t_node * Node, int key);
            // Deletion                                    
            t_node * deleteNode(t_node * Node, int key);
            // Search
            t_node* SearchKey(t_node * root, int key);
            // Rotation
                // rotate key roted with y
            t_node * RightRotate(t_node * y);
                // rotate key roted with x
            t_node * LeftRotate(t_node * x);
                // right rotate 
            t_node * LeftLeftRotate(t_node *x,t_node *y);
                // left rotate then right rotate
            t_node * LeftRightRotate(t_node *x, t_node *y);
                // left rotate
            t_node * RightRightRotate(t_node *x, t_node *y);
                // right rotate then left rotate
            t_node * RightLeftRotate(t_node *x, t_node *y);

                // Print Tree
                    // types of traversal
                // - inerdor traversal
            void printInOrder(t_node * root) const;
                // - preorder traversal 
            void printPreOrder(t_node * root) const;
                // - postorder traversal
            void printPostOrder(t_node * root) const;
                // factor of balance should be -1 0 +1 :  height(left-subtree)-height(right-subtree)
            int getBalanceFactor(t_node * N) const;
                //
            int         getHeight(t_node * Node) const;
                //
            t_node *    getMinValueNode(t_node * Node) const;
                //
            
    };

}

#endif