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
    typedef struct  s_node
    {
        int                data;      // pair<key, value>
        struct s_node *    left;
        struct s_node *    right;
        struct s_node *    parent;
        int                height;
    }               t_node;

    class AVL_Tree
    {
        private:
            
            int                 _size;
            int                 _height;
            int                 _balance_factor; // balancing happen when balance factor does not satisfy <=1 condition     
                                            //" (-1 <= Balance Factor >= 1) = height(left-subtree) − height(right-subtree) "   correct balance factor is 1, 0 and -1.
        
        // Properties Of Binary tree  ( max nodes using level : 2^l / max node using height : 2^height - 1/ 
        //                            / minimum possible height or minimum possible level with N Nodes : Log2(N+1)
        
        public:
            t_node * root;

            t_node * CreateNode(int value = 0)
            {
                t_node * node = new t_node();
                node->data = value;
                node->height = 0;
                node->left = NULL;
                node->right = NULL;
                node->parent = NULL;
                return node;
            }

            t_node * insertNode(const t_node & Node)
            {
                if (root = NULL)
                    return NULL;
                
                
            }
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


        // Operations On a AVL_Tree
            // Insertion

            // Deletion

            // Search

            // Rotation

            // Print Tree

            // types of traversal
            // - inerdor traversal (root midlane)
            // - preorder traversal (root at left then left then right)
            // - postorder traversal (root at the right after left node and right node respectivly)
    };

}

#endif