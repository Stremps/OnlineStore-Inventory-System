# Online Sales Product Management System

## Description
This repository contains the implementation of an online sales product management system designed for managing a dynamic catalog of products. Developed as part of the Data Structures II course at UNIOESTE, this project utilizes binary trees for efficient data management and binary files for data storage.

## Features
The system supports various operations that can be performed on the product catalog, which are outlined below:

- **Add Product**: Registers a new product with details provided by the user.
- **Remove Product**: Deletes a product from the catalog using its unique code.
- **Update Price**: Updates the price of a product identified by its code.
- **Update Stock**: Updates the stock quantity of a product based on its code.
- **Print Product Information**: Displays detailed information about a product using its code.
- **Print All Products**: Executes an in-order traversal of the binary tree to print codes and names of all products.
- **Print Binary Tree**: Visually displays the structure of the tree by printing product codes arranged as a tree.
- **Print Free List**: Shows a list of free nodes in the tree due to removals.
- **Batch Operations**: Performs batch insertions, updates, and deletions from a loaded text file.

### Technical Characteristics
- **Implementation**: Written in C.
- **Data Structure**: Binary Tree.
- **Storage**: Binary files, with free nodes managed in a linked free list for reuse.

## Current Limitations
While the implementation is functionally complete and robust, the documentation may still be limited due to the initial programming experience. Further documentation enhancements are planned.

## How to Use
### Compilation and Execution
To compile and run the program on a Linux environment, use the following commands:
```bash
gcc -o productManager *.c
./productManager
