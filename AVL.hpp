//
//  AVL.hpp
//  AVL
//
//  Created by Ankit Yadav on 12/22/23.
//

#ifndef AVL_hpp
#define AVL_hpp

#include <iostream>

using namespace std;

/**
 * @struct node
 * @brief Structure representing a node in the AVL tree.
 *
 * Each node contains a parent pointer, left and right child pointers,
 * a key, and the height of the node in the tree.
 */
struct node {
    node * parent;
    node * left;
    node * right;
    int    key;
    int    height;
};

/**
 * @class AVLTree
 * @brief Class representing the AVL tree.
 *
 * The AVLTree class provides methods for performing various operations on the AVL tree,
 * such as insertion, removal, finding, and displaying elements.
 */
class AVLTree {

public:

           AVLTree        ();

           ~AVLTree       ();

    void   insert         (int pKey);

    void   remove         (int pKey);

    bool   find           (int pKey);

    void   displayTree    ();

private:

    node * next           (node * pNode);

    node * leftDescendent (node * pNode);

    node * rightAnscestor (node * pNode);
    
    void   insert         (node * pNode, int pKey);

    void   remove         (node * pNode);

    node * find           (node * pNode, int pKey);

    void   rebalance      (node * pNode);

    void   rebalanceRight (node * pNode);

    void   rebalanceLeft  (node * pNode);

    void   rotateRight    (node * pNode);

    void   rotateLeft     (node * pNode);

    void   adjustHeight   (node * pNode);

    void   inorder        (node * pNode);

    int    height         (node * pNode);
    
    void   destroy        (node * pNode);

    node * root; ///< Pointer to the root node of the AVL tree.
};

#endif /* AVL_hpp */
