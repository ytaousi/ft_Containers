#ifndef TREE_HPP
#define TREE_HPP

namespace ft
{
    class AVL_Node
    {
        protected:
            int                 _data;      // pair<key, value>
            class AVL_Node *    _left;
            class AVL_Node *    _right;
            class AVL_Node *    _parent;
            int                 _height;
        
        public:
            AVL_Node() : _data(0), _left(NULL), _right(NULL), _height(0)
            {

            }
            AVL_Node(int data) : _data(data), _left(NULL), _right(NULL), _height(0)
            {

            }
            ~AVL_Node()
            {
                
            }
            AVL_Node(const AVL_Node & instance) : _data(0), _left(NULL), _right(NULL), _height(0)
            {
                *this = instance;
            }
            AVL_Node & operator=(const AVL_Node & instance)
            {
                _data = instance._data;
                _left = instance._left;
                _right = instance._right;
                _parent = instance._parent;
                _height = instance._height;
                return *this;
            }

            friend bool operator==(const AVL_Node &lhs, const AVL_Node &rhs);
            friend bool operator!=(const AVL_Node &lhs, const AVL_Node &rhs);
            friend bool operator<(const AVL_Node &lhs, const AVL_Node &rhs);
            friend bool operator>(const AVL_Node &lhs, const AVL_Node &rhs);
            friend bool operator<=(const AVL_Node &lhs, const AVL_Node &rhs);
            friend bool operator>=(const AVL_Node &lhs, const AVL_Node &rhs);
    };

    bool operator==(const AVL_Node &lhs, const AVL_Node &rhs)
    {
        return (lhs._data == rhs._data)
    }

    bool operator!=(const AVL_Node &lhs, const AVL_Node &rhs)
    {
        return (!(lhs._data == rhs._data))
    }

    bool operator<(const AVL_Node &lhs, const AVL_Node &rhs)
    {
        return (lhs._data < rhs._data);
    }
    bool operator>(const AVL_Node &lhs, const AVL_Node &rhs)
    {
        return (lhs._data > rhs._data);
    }
    bool operator<=(const AVL_Node &lhs, const AVL_Node &rhs)
    {
        return (( (lhs._data < rhs._data) || (lhs._data == rhs._data) ))
    }
    bool operator>=(const AVL_Node &lhs, const AVL_Node &rhs)
    {
        return (( (lhs._data > rhs._data) || (lhs._data == rhs._data) ))
    }
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

    class AVL_Tree
    {
        private:
            class AVL_Node *    root;
            int                 _size;
            int                 _height;
            int                 _balance_factor; // balancing happen when balance factor does not satisfy <=1 condition     
                                            //" (-1 <= Balance Factor >= 1) = height(left-subtree) − height(right-subtree) "   correct balance factor is 1, 0 and -1.
        
        // Properties Of Binary tree  ( max nodes using level : 2^l / max node using height : 2^height - 1/ 
        //                            / minimum possible height or minimum possible level with N Nodes : Log2(N+1)
        
        public:
            AVL_Tree() : root(NULL), _size(0), _height(0), _balance_factor(0)
            {
                root = new AVL_Node(42);
                root.left = new AVL_Node(14);
                root.right = new AVL_Node(43);
            }
            ~AVL_Tree()
            {
                delete root.left;
                delete root.right;
                delete root;
            }
            AVL_Tree(const AVL_Tree& instance) : root(NULL), _size(0), _height(0), _balance_factor(0)
            {
                *this = instance;
            }

            friend bool operator==(const AVL_Tree&lhs, const AVL_Tree&rhs);
            friend bool operator!=(const AVL_Tree&lhs, const AVL_Tree&rhs);
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

    bool operator==(const AVL_Tree&lhs, const AVL_Tree&rhs)
    {

    }
    bool operator!=(const AVL_Tree&lhs, const AVL_Tree&rhs)
    {

    }
}

#endif