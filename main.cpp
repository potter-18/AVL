//
//  main.cpp
//  AVL
//
//  Created by Ankit Yadav on 12/22/23.
//

#include <iostream>
#include "AVL.hpp"

using namespace std;

int main() {
    // insert code here...
    
    AVLTree avlTree;

        // Test Case 1: Insertion of Already Existing Nodes
        std::cout << "Test Case 1 - Insertion of Already Existing Nodes:\n";
        avlTree.insert(50);
        avlTree.insert(30);
        avlTree.insert(70);
        avlTree.insert(30);  // This insertion should not change the tree
        avlTree.displayTree();
        std::cout << "\n\n";

        // Test Case 2: Random Insertions
        std::cout << "Test Case 2 - Random Insertions:\n";
        avlTree.insert(45);
        avlTree.insert(80);
        avlTree.insert(20);
        avlTree.insert(60);
        avlTree.displayTree();
        std::cout << "\n\n";

        // Test Case 3: Sequential Insertions
        std::cout << "Test Case 3 - Sequential Insertions:\n";
        for (int i = 1; i <= 5; ++i) {
            avlTree.insert(i);
        }
        avlTree.displayTree();
        std::cout << "\n\n";

        // Test Case 4: Deletion of Nonexistent Nodes
        std::cout << "Test Case 4 - Deletion of Nonexistent Nodes:\n";
        avlTree.remove(10);  // This deletion should not change the tree
        avlTree.displayTree();
        std::cout << "\n\n";

        // Test Case 5: Deletion of Leaf Nodes
        std::cout << "Test Case 5 - Deletion of Leaf Nodes:\n";
        avlTree.remove(1);
        avlTree.remove(5);
        avlTree.displayTree();
        std::cout << "\n\n";

        // Test Case 6: Deletion of Nodes with One Child
        std::cout << "Test Case 6 - Deletion of Nodes with One Child:\n";
        avlTree.remove(3);
        avlTree.displayTree();
        std::cout << "\n\n";

        // Test Case 7: Deletion of Nodes with Two Children
        std::cout << "Test Case 7 - Deletion of Nodes with Two Children:\n";
        avlTree.remove(2);
        avlTree.displayTree();
        std::cout << "\n\n";

        // Test Case 8: Mixed Operations
        std::cout << "Test Case 8 - Mixed Operations:\n";
        avlTree.insert(15);
        avlTree.remove(4);
        avlTree.displayTree();
        std::cout << "\n\n";

        // Test Case 9: Extreme Cases
        std::cout << "Test Case 9 - Extreme Cases:\n";
        for (int i = 100; i >= 1; --i) {
            avlTree.insert(i);
        }
        avlTree.displayTree();
        std::cout << "\n\n";

        // Test Case 10: Concurrency (Note: Implement concurrency testing if applicable)

        return 0;
    
    return 0;
}
