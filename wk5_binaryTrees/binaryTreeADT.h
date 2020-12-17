/*************************************
*   Author: Eric Johnson
*   Date: 12/16/2020
*
*   Grantham University
*   CS325 Data Structures
* 
*   Week 5 Assignment
*   Binary Search Trees
*
*   This file is a header file that defines a binary 
*   tree abstract class.
*************************************/

#ifndef binaryTreeADT_h
#define binaryTreeADT_h

template <class T>    // Define the node type
struct node{
    T data;
    node<T> *lLink;
    node<T> *rLink;
};

template <class T>
class binaryTree{
    public:
        const binaryTreeType<T> &operator=(const binaryTree<T>&);
            //Overload the assignment operator.

        bool isEmpty() const;
            //Function to determine whether the binary tree is empty.
            //Postcondition: Returns true if the binary tree is empty;
            //               otherwise, returns false.
        
        void inorderTraversal() const;
            //Function to do an inorder traversal of the binary tree.
            //Postcondition: Nodes are printed in inorder sequence.
        
        void preorderTraversal() const;
            //Function to do a preorder traversal of the binary tree.
            //Postcondition: Nodes are printed in preorder sequence.

        void postorderTraversal() const;
            //Function to do a postorder traversal of the binary tree.
            //Postcondition: Nodes are printed in postorder sequence.

        int treeHeight() const;
            //Function to determine the height of a binary tree.
            //Postcondition: Returns the height of the binary tree.

        int treeNodeCount() const;
            //Function to determine the number of nodes in a binary tree.
            //Postcondition: Returns the number of nodes in the binary tree.

        int treeLeavesCount() const;
            //Function to determine the number of leaves in a binary tree.
            //Postcondition: Returns the number of leaves in the binary tree.
        
        void destroyTree();
            //Function to destroy the binary tree.
            //Postcondition: Memory space occupied by each node is deallocated.
            //               root = nullptr;

        virtual bool search(const T &searchItem) const = 0;
            //Function to determine if searchItem is in the binary tree.
            //Postcondition: Returns true if searchItem is found in the 
            //               binary tree; otherwise, returns false.

        virtual void insert(const T & insertItem) = 0;
            //Function to insert insertItem in the binary tree.
            //Postcondition: If there is no node in the binary tree that
            //               has the same info as insertItem, a node with 
            //               the info insertItem is created and inserted
            //               in the binary search tree.

        virtual void deleteNode(const T & deleteItem) = 0;
            //Function to delete deleteItem from the binary tree.
            //Postcondition: If a node with the same info as deleteItem
            //               is found, it is deleted from the binary tree.
            //               If the binary tree is empty or deleteItem is not
            //               in the binary tree, an appropriate message is printed.

        binaryTree(const binartyTree<T> &otherTree);
            //Copy constructor
        
        binaryTree();
            //Default constructor
        
        ~binaryTree();
            //Destructor

    protected:
        node<T> *root;

    private:
        void copyTree(node<T> *&copiedTreeRoot, node<T> *otherTreeRoot);
            //Makes a copy of the binary tree to which otherTreeRoot points.
            //Postcondition: The pointer copiedTreeRoot points to the root 
            //               of the copied binary tree.

        void destroy(node<T> *&p);
            //Function to destroy the binary tree to which p points.
            //Postcondition: Memory space occupied by each node, in the 
            //               binary tree to which p points, is deallocated.
            //               p = nullptr;

        void inorder(node<T> *p) const;
            //Function to do an inorder traversal of the binary tree to which p points.
            //Postcondition: Nodes of the binary tree, to which p points, are printed
            //               in inorder sequence.

        void preorder(node<T> *p) const;
            //Function to do a preorder traversal of the binary tree to which p points.
            //Postcondition: Nodes of the binary tree, to which p points, are printed
            //               in preorder sequence.

        void postorder(node<T> *p) const;
            //Function to do a postorder traversal of the binary tree to which p points.
            //Postcondition: Nodes of the binary tree, to which p points, are printed in 
            //               postorder sequence.

        int height(node<T> *p) const;
            //Function to determine the height of the binary tree to which p points.
            //Postcondition: Height of the binary tree to which p points is returned.

        int max(int x, int y) const;
            //Function to determine the larger of x and y.
            //Postcondition: Returns the larger of x and y.

        int nodeCount(node<T> *p) const;
            //Function to determine the number of nodes in the binary tree to which p points.
            //Postcondition: The number of nodes in the binary tree to which p points is returned.

        int leavesCount(node<T> *p) const;
            //Function to determine the number of leaves in the binary tree to which p points
            //Postcondition: The number of leaves in the binary tree to which p points is returned.
};

#endif