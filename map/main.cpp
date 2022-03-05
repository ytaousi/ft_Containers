//#include "tree.hpp"
#include "templated_tree.hpp"
#include "pair.hpp"

using namespace ft;

int main()
{
    AVL_Treee<int, std::less<int>, std::allocator<int> > _NotReadBlackTree;

    _NotReadBlackTree._root = _NotReadBlackTree.insertNode(_NotReadBlackTree._root, 4);
    _NotReadBlackTree._root = _NotReadBlackTree.insertNode(_NotReadBlackTree._root, 33);
    _NotReadBlackTree._root = _NotReadBlackTree.insertNode(_NotReadBlackTree._root, 30);
    _NotReadBlackTree._root = _NotReadBlackTree.insertNode(_NotReadBlackTree._root, 100);
    _NotReadBlackTree._root = _NotReadBlackTree.insertNode(_NotReadBlackTree._root, 102);
    _NotReadBlackTree._root = _NotReadBlackTree.insertNode(_NotReadBlackTree._root, 66);
    std::cout << "Minimal Value" << std::endl;
    std::cout << _NotReadBlackTree.getMinValueNode(_NotReadBlackTree._root)->content << std::endl;
    std::cout << "InorderTreeTraversal" << std::endl;
    _NotReadBlackTree.printInOrder(_NotReadBlackTree._root);
    std::cout << std::endl;
    _NotReadBlackTree._root = _NotReadBlackTree.deleteNode(_NotReadBlackTree._root, 102);
    _NotReadBlackTree.printInOrder(_NotReadBlackTree._root);
    return (0);
}