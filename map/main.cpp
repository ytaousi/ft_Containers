#include "tree.hpp"

using namespace ft;

int main()
{
    AVL_Tree _NotReadBlackTree;

    _NotReadBlackTree.root = _NotReadBlackTree.insertNode(_NotReadBlackTree.root, 44);
    _NotReadBlackTree.root = _NotReadBlackTree.insertNode(_NotReadBlackTree.root, 33);
    _NotReadBlackTree.root = _NotReadBlackTree.insertNode(_NotReadBlackTree.root, 10);
    _NotReadBlackTree.root = _NotReadBlackTree.insertNode(_NotReadBlackTree.root, 11);
    _NotReadBlackTree.root = _NotReadBlackTree.insertNode(_NotReadBlackTree.root, 55);
    _NotReadBlackTree.root = _NotReadBlackTree.insertNode(_NotReadBlackTree.root, 13);
    _NotReadBlackTree.root = _NotReadBlackTree.insertNode(_NotReadBlackTree.root, 20);
    _NotReadBlackTree.printInOrder(_NotReadBlackTree.root);
    std::cout << std::endl;
    //std::cout << _NotReadBlackTree.root->key << std::endl;
    return (0);
}