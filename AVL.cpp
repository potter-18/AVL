//
//  AVL.cpp
//  AVL
//
//  Created by Ankit Yadav on 12/22/23.
//

#include "AVL.hpp"

/**
 * @brief Default constructor for the AVL tree.
 *
 * This function initializes the AVL tree by setting the root pointer to nullptr.
 */
AVLTree::AVLTree ()
{
    root = nullptr;
}

/**
 * @brief Destructor for the AVL tree.
 *
 * This function destructs the AVL tree by recursively deleting each node starting from the root.
 */
AVLTree::~AVLTree ()
{
    destroy (root);
}

/**
 * @brief Insert a node with the specified key into the AVL tree.
 *
 * This function inserts a new node with the given key into the AVL tree. If the tree is empty,
 * it creates the root node; otherwise, it calls the InternalInsert function to find the appropriate
 * position for the new node.
 *
 * @param pKey The key of the node to be inserted.
 */
void AVLTree::insert (int pKey)
{
        node * current_node;

    if (root == nullptr) {

        root         = new node;
        root->parent = nullptr;
        root->height = 1;
        root->left   = nullptr;
        root->right  = nullptr;
        root->key    = pKey;
    } else {

        insert (root, pKey);
    }

    current_node = find (root, pKey);

    rebalance (current_node);
}

/**
 * @brief Remove a node with the specified key from the AVL tree.
 *
 * This function removes a node with the given key from the AVL tree. If the node is not present in
 * the tree, a message is printed to the console.
 *
 * @param pKey The key of the node to be removed.
 */
void AVLTree::remove (int pKey)
{
        node * required_node;

    required_node = find (root, pKey);

    if (required_node->key != pKey) {
        
        printf("Node with key %d not present in tree!\n", pKey);
        return;
    }
    remove (required_node);

    rebalance (required_node->parent);

    delete required_node;
}

/**
 * @brief Check if a node with a given key exists in the AVL tree.
 *
 * This function checks if a node with the specified key exists in the AVL tree.
 *
 * @param pKey The key to search for in the AVL tree.
 * @return True if a node with the key exists, false otherwise.
 */
bool AVLTree::find (int pKey)
{
            node * requested_node;

    requested_node = find (root, pKey);
    
    if (requested_node->key == pKey) {
        
        return true;
    } else {
        
        return false;
    }
}

/**
 * @brief Display the keys of nodes in the AVL tree in inorder traversal.
 *
 * This function displays the keys of nodes in the AVL tree in inorder traversal.
 */
void AVLTree::displayTree ()
{
    inorder (root);
    printf ("\n");
}

/**
 * @brief Find the next node in the inorder traversal of the AVL tree.
 *
 * This function finds the next node in the inorder traversal of the AVL tree, given the current node.
 * If the current node has a right child, the next node is the leftmost descendent of the right child.
 * Otherwise, the next node is the right ancestor of the current node. If no next node exists, the
 * function returns nullptr.
 *
 * @param pNode The current node for which to find the next node.
 * @return The next node in the inorder traversal or nullptr if none exists.
 */
node * AVLTree::next (node * pNode)
{
    if (pNode->right != nullptr) {

        return leftDescendent (pNode->right);
    } else {

        return rightAnscestor (pNode);
    }
}

/**
 * @brief Find the leftmost descendent of a given node in the AVL tree.
 *
 * This function finds the leftmost descendent of the specified node in the AVL tree. The leftmost
 * descendent is the node with the smallest key in the subtree rooted at the current node. If the
 * current node has no left child, the function returns the current node itself.
 *
 * @param pNode The node for which to find the leftmost descendent.
 * @return The leftmost descendent node.
 */
node * AVLTree::leftDescendent (node * pNode)
{
    if (pNode->left != nullptr) {

        return leftDescendent (pNode->left);
    } else {

        return pNode;
    }
}

/**
 * @brief Find the right ancestor of a given node in the AVL tree.
 *
 * This function finds the right ancestor of the specified node in the AVL tree. The right ancestor
 * is the nearest ancestor that is to the right of the current node. If no right ancestor exists,
 * the function returns nullptr.
 *
 * @param pNode The node for which to find the right ancestor.
 * @return The right ancestor node or nullptr if none exists.
 */
node * AVLTree::rightAnscestor (node * pNode)
{
    if (pNode->key < pNode->parent->key) {

        return pNode->parent;
    } else {

        return rightAnscestor (pNode->parent);
    }
}

/**
 * @brief Internal function to insert a new node with the given key into the AVL tree.
 *
 * This function inserts a new node with the specified key into the AVL tree and adjusts the
 * tree structure and heights accordingly. If a node with the same key already exists, it prints
 * an error message and does not insert the new node.
 *
 * @param pNode The current node in the insertion process.
 * @param pKey The key of the new node to be inserted.
 */
void AVLTree::insert (node * pNode, int pKey)
{
        node * required_node;
        node * new_node;

    required_node     = find (pNode, pKey);
    
    if (required_node->key == pKey) {
        
        printf ("Node with key %d already Present!\n", required_node->key);
        return;
    }
    
    new_node          = new node;
    new_node->parent = required_node;
    new_node->left   = nullptr;
    new_node->right  = nullptr;
    new_node->key    = pKey;

    if (required_node->key > pKey) {

        required_node->left = new_node;
    } else {

        required_node->right = new_node;
    }
    
    adjustHeight(new_node);
}

/**
 * @brief Internal function to remove a node from the AVL tree.
 *
 * This function removes the specified node from the AVL tree and adjusts the tree structure
 * and heights accordingly. If the node has a right child, it is replaced by its successor,
 * and the successor is then removed.
 *
 * @param pNode The node to be removed.
 */
void AVLTree::remove (node * pNode)
{
        node * temp_node = nullptr;

    if (pNode->right == nullptr) {

        if (pNode->left != nullptr) {
            
            pNode->left->parent = pNode->parent;
        }
        

        if (pNode->parent->left == pNode) {

            pNode->parent->left = pNode->left;
        } else {

            pNode->parent->right = pNode->left;
        }
    } else {

        temp_node = next (pNode);
        
        if (temp_node != pNode->right) {
            
            if (temp_node->parent->left == temp_node) {

                temp_node->parent->left = temp_node->right;
            } else {

                temp_node->parent->right = temp_node->right;
            }
            
            temp_node->right->parent = temp_node->parent;
        }

        if (pNode->parent->left == pNode) {

            pNode->parent->left = temp_node;
        } else {

            pNode->parent->right = temp_node;
        }
        
        if (pNode->left != nullptr) {
            
            pNode->left->parent = temp_node;
        }
        
        temp_node->left      = pNode->left;
        temp_node->parent    = pNode->parent;
        
        adjustHeight (temp_node);
    }
}

/**
 * @brief Internal function to find a node with the given key in the AVL tree.
 *
 * This function recursively searches for a node with the specified key in the AVL tree
 * starting from the given node. If the key is found, the function returns the node.
 * If the key is not found, the function returns the last node reached during the search,
 * which will be the parent of the desired node.
 *
 * @param pNode The current node in the search.
 * @param pKey The key to search for.
 * @return The node with the specified key or the last node reached during the search.
 */
node * AVLTree::find (node * pNode, int pKey)
{
    if (pNode->key == pKey) {

        return pNode;
    } else if (pNode->key > pKey) {

        if (pNode->left != nullptr)
            return find (pNode->left, pKey);

        return pNode;
    } else {

        if(pNode->right != nullptr)
            return find (pNode->right, pKey);

        return pNode;
    }
}

/**
 * @brief Rebalances the AVL tree starting from the given node.
 *
 * This function performs the necessary rotations to rebalance the AVL tree
 * starting from the specified node. It checks the balance factor of the node
 * and performs the appropriate rotations. The rebalancing is propagated up the tree,
 * and the heights of the affected nodes are adjusted.
 *
 * @param pNode The node around which to perform rebalancing.
 */
void AVLTree::rebalance (node * pNode)
{
        node * parent;

    parent = pNode->parent;

    if (height (pNode->left) > height (pNode->right) + 1) {

        rebalanceRight (pNode);
    }

    if (height (pNode->right) > height (pNode->left) + 1) {

        rebalanceLeft (pNode);
    }
    
    adjustHeight (pNode);

    if (parent != nullptr) {

        rebalance (parent);
    }
}

/**
 * @brief Rebalances the AVL tree when the left subtree is taller.
 *
 * This function performs the necessary rotations to rebalance the AVL tree
 * when the left subtree of the specified node is taller.
 * It first checks if a left-right rotation is needed, and then performs a right rotation.
 *
 * @param pNode The node around which to perform rebalancing.
 */
void AVLTree::rebalanceRight (node * pNode)
{
        node * left;

    left = pNode->left;

    if (height (left->right) > height (left->left)) {

        rotateLeft (left);
    }

    rotateRight (pNode);
}

/**
 * @brief Rebalances the AVL tree when the right subtree is taller.
 *
 * This function performs the necessary rotations to rebalance the AVL tree
 * when the right subtree of the specified node is taller.
 * It first checks if a right-left rotation is needed, and then performs a left rotation.
 *
 * @param pNode The node around which to perform rebalancing.
 */
void AVLTree::rebalanceLeft (node * pNode)
{
        node * right;

    right = pNode->right;

    if (height (right->left) > height (right->right)) {

        rotateRight (right);
    }

    rotateLeft (pNode);
}

/**
 * @brief Performs a right rotation on the AVL tree rooted at the given node.
 *
 * This function performs a right rotation on the AVL tree rooted at the specified node.
 * It updates the tree structure and adjusts the heights of the affected nodes.
 *
 * @param pNode The node around which to perform the right rotation.
 */
void AVLTree::rotateRight (node * pNode)
{
        node * parent;
        node * left;
        node * left_right;

    parent     = pNode->parent;
    left       = pNode->left;
    left_right = left->right;

    left->parent = parent;

    if (parent == nullptr) {

        root = left;
    } else if (parent->left == pNode){

        parent->left = left;
    } else {

        parent->right = left;
    }

    pNode->parent = left;
    left->right   = pNode;

    if (left_right != nullptr) {

        left_right->parent = pNode;
    }

    pNode->left = left_right;
    
    adjustHeight (pNode);
}

/**
 * @brief Performs a left rotation on the AVL tree rooted at the given node.
 *
 * This function performs a left rotation on the AVL tree rooted at the specified node.
 * It updates the tree structure and adjusts the heights of the affected nodes.
 *
 * @param pNode The node around which to perform the left rotation.
 */
void AVLTree::rotateLeft (node * pNode)
{
        node * parent;
        node * right;
        node * right_left;

    parent     = pNode->parent;
    right      = pNode->right;
    right_left = right->left;

    right->parent = parent;

    if (parent == nullptr) {

        root = right;
    } else if (parent->left == pNode){

        parent->left = right;
    } else {

        parent->right = right;
    }

    pNode->parent = right;
    right->left   = pNode;

    if (right_left != nullptr) {

        right_left->parent = pNode;
    }

    pNode->right = right_left;
    
    adjustHeight (pNode);
}

/**
 * @brief Adjusts the height of the given node in the AVL tree and propagates the changes up the tree.
 *
 * This function recalculates and updates the height of the specified AVL tree node.
 * It then propagates the height adjustment up the tree by recursively calling itself
 * on the node's parent, ensuring that the AVL tree remains balanced.
 *
 * @param pNode The node for which to adjust the height.
 */
void AVLTree::adjustHeight(node * pNode)
{
        node * parent;
    
    parent = pNode->parent;
    
    if (pNode->left == nullptr && pNode->right == nullptr) {

        pNode->height = 1;
    } else if (height (pNode->left) > height (pNode->right)) {

        pNode->height = 1 + height (pNode->left);
    } else {

        pNode->height = 1 + height (pNode->right);
    }
    
    if (parent != nullptr) {
        
        adjustHeight(parent);
    }
}

/**
 * @brief Performs an inorder traversal of the AVL tree starting from the given node.
 *
 * This function recursively traverses the AVL tree in an inorder manner,
 * printing the key of each node along the way.
 *
 * @param pNode The root node of the subtree to traverse.
 */
void AVLTree::inorder (node * pNode)
{
    if (pNode == nullptr) {

        return;
    }

    inorder (pNode->left);
    printf ("%d->", pNode->key);
    inorder (pNode->right);
}

/**
 * @brief Returns the height of the given node in the AVL tree.
 *
 * This function calculates and returns the height of the specified AVL tree node.
 * If the node is nullptr, it returns 0, indicating an empty subtree.
 *
 * @param pNode The node for which to determine the height.
 * @return The height of the node (0 for nullptr).
 */
int AVLTree::height (node * pNode)
{
    if (pNode == nullptr) {

        return 0;
    }

    return pNode->height;
}

/**
 * @brief Recursively destroys the nodes of the AVL tree.
 *
 * This function recursively deletes the nodes of the AVL tree starting from the given node.
 * It performs a post-order traversal to ensure proper cleanup.
 *
 * @param pNode The root node of the subtree to be destroyed.
 */
void AVLTree::destroy (node * pNode)
{
    if (pNode == nullptr) {
        
        return;
    }
    
    destroy(pNode->left);
    destroy(pNode->right);
    
    delete pNode;
}
