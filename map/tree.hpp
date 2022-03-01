#ifndef TREE_HPP
#define TREE_HPP


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
    class AVL_Node
    {
        protected:
            int                 _data; // pair<key, value>
            class AVL_Node *    _left;
            class AVL_Node *    _right;
            int                 _balance_factor; // balancing happen when balance factor does not satisfy <=1 condition    " Balance Factor = height(left-subtree) − height(right-subtree) "   correct balance factor is 1, 0 and -1.
        
        public:
            AVL_Node() : _data(0), _left(NULL), _right(NULL)
            {

            }
            AVL_Node(int data) : _data(data) , _balance_factor(0) , _left(NULL), _right(NULL)
            {

            }
            ~AVL_Node()
            {
                
            }
            AVL_Node(const AVL_Node & instance) : _data(0),  _balance_factor(0), _left(NULL), _right(NULL)
            {
                *this = instance;
            }
            AVL_Node & operator=(const AVL_Node & instance)
            {
                _data = instance._data;
                _balance_factor = instance._balance_factor;
                _left = instance._left;
                _right = instance._right;    
                return *this;
            }
    };
}

#endif