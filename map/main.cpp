#include "tree.hpp"

using namespace ft;

int main()
{
    AVL_Tree _NotReadBlackTree;

    _NotReadBlackTree.root = _NotReadBlackTree.insertNode(_NotReadBlackTree.root, 22);
    _NotReadBlackTree.root = _NotReadBlackTree.insertNode(_NotReadBlackTree.root, 33);
    _NotReadBlackTree.root = _NotReadBlackTree.insertNode(_NotReadBlackTree.root, 30);
    _NotReadBlackTree.root = _NotReadBlackTree.insertNode(_NotReadBlackTree.root, 100);
    _NotReadBlackTree.root = _NotReadBlackTree.insertNode(_NotReadBlackTree.root, 102);
    _NotReadBlackTree.root = _NotReadBlackTree.insertNode(_NotReadBlackTree.root, 66);
    std::cout << std::endl;
    std::cout << _NotReadBlackTree.getMinValueNode(_NotReadBlackTree.root)->key << std::endl;
    std::cout << std::endl;
    //_NotReadBlackTree.printInOrder(_NotReadBlackTree.root);
    return (0);
}