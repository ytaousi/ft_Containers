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
    std::cout << "Minimal Value" << std::endl;
    std::cout << _NotReadBlackTree.getMinValueNode(_NotReadBlackTree.root)->key << std::endl;
    std::cout << std::endl;
    std::cout << "Maximal Value" << std::endl; 
    std::cout << _NotReadBlackTree.getMaxValueNode(_NotReadBlackTree.root)->key << std::endl;

    //std::cout << "InorderTreeTraversal" << std::endl;
    //_NotReadBlackTree.printInOrder(_NotReadBlackTree.root);
    std::cout << std::endl;
    //_NotReadBlackTree.root = _NotReadBlackTree.deleteNode(_NotReadBlackTree.root, 102);
    _NotReadBlackTree.printBT(_NotReadBlackTree.root);
    return (0);
}