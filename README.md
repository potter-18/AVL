# C++ AVL Tree Implementation

This repository contains a C++ implementation of an AVL (Adelson-Velsky and Landis) tree, a self-balancing binary search tree. AVL trees maintain their balance during insertions and deletions, ensuring efficient search, insertion, and deletion operations with a logarithmic time complexity.

## Overview

AVL trees are binary search trees with the additional property that the height of the two child subtrees of every node differs by at most one. This ensures that the tree remains balanced, preventing degeneration into a linked list and maintaining efficient operations.

This implementation is split across three files: `AVL.hpp` (header file), `AVL.cpp` (implementation file), and `main.cpp` (main program). The separation of the header and implementation files allows for modularity and clean code organization.

## Features

- **Self-Balancing**: AVL trees automatically balance themselves, ensuring efficient operations.
- **Insertion, Deletion, and Search**: Standard binary search tree operations are supported.
- **Modular Design**: The code is organized in a modular fashion for easy understanding and extensibility.
- **Well-Commented Code**: Extensive comments in the code for clear understanding.

## File Structure

- `AVL.hpp`: Header file containing the class declaration for the AVL tree.
- `AVL.cpp`: Implementation file containing the definitions for the AVL tree methods.
- `main.cpp`: Main program demonstrating the usage of the AVL tree.

## Usage

To use the AVL tree in your C++ project, follow these steps:

1. Clone the repository: `git clone https://github.com/yourusername/avl-tree-cpp.git`
2. Include the header file `AVL.hpp` in your main program.
3. Implement the AVL tree operations using the provided methods.

Refer to the [example](#example) section for a quick demonstration.

## Installation

There is no separate installation process required. Simply include the necessary files in your C++ project.

## Example

```cpp
// main.cpp
#include "AVL.hpp"

int main() {
    // Create an AVL tree
    AVLTree<int> avlTree;

    // Insert elements
    avlTree.insert(10);
    avlTree.insert(5);
    avlTree.insert(15);

    // Search for an element
    bool result = avlTree.search(5);
    std::cout << "Search Result: " << result << std::endl;

    // Delete an element
    avlTree.remove(10);

    // Print the AVL tree
    avlTree.printTree();

    return 0;
}

## Contributing

Contributions are welcome! We encourage you to contribute to the improvement of this AVL tree implementation. To contribute, please follow these guidelines:
Please ensure that your code adheres to the existing coding standards, and include appropriate tests for new features.

## License

This AVL tree implementation is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
