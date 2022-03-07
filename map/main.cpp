//#include "tree.hpp"
//#include "templated_tree.hpp"
#include "pair.hpp"
#include "tree.hpp"
//#include "../../tests/map/rbtVD1.hpp"
//#include "../../tests/map/map.hpp"

using namespace ft;

int main()
{
    AVL_Tree _NotReadBlackTree;

    _NotReadBlackTree.root = _NotReadBlackTree.insertNode(_NotReadBlackTree.root, 4);
    _NotReadBlackTree.root = _NotReadBlackTree.insertNode(_NotReadBlackTree.root, 33);
    _NotReadBlackTree.root = _NotReadBlackTree.insertNode(_NotReadBlackTree.root, 30);
    _NotReadBlackTree.root = _NotReadBlackTree.insertNode(_NotReadBlackTree.root, 100);
    _NotReadBlackTree.root = _NotReadBlackTree.insertNode(_NotReadBlackTree.root, 102);
    _NotReadBlackTree.root = _NotReadBlackTree.insertNode(_NotReadBlackTree.root, 66);
    _NotReadBlackTree.root = _NotReadBlackTree.insertNode(_NotReadBlackTree.root, 13);
    std::cout << std::endl;
    //std::cout << "InorderTreeTraversal" << std::endl;
    //_NotReadBlackTree.printInOrder(_NotReadBlackTree.root);
    std::cout << std::endl;
    _NotReadBlackTree.printBT(_NotReadBlackTree.root);
    return (0);
}