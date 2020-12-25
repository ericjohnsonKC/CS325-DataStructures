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

#include <iostream>


template <class T>    // Define the node type
struct node{
    T data;
    node<T> *lLink;
    node<T> *rLink;
};

template <class T>
class binaryTree{
    public:
        const binaryTree<T> &operator=(const binaryTree<T>&);
            //Overload the assignment operator.

        bool isEmpty() const;
            //Function to determine whether the binary tree is empty.
            //Postcondition: Returns true if the binary tree is empty;
            //               otherwise, returns false.
        
        void inorderTraversal(void (*visit) (T &item)) const;
            //Function to do an inorder traversal of the binary tree.
            //Postcondition: Nodes are visited in inorder sequence.
        
        void preorderTraversal(void (*visit) (T &item)) const;
            //Function to do a preorder traversal of the binary tree.
            //Postcondition: Nodes are printed in preorder sequence.

        void postorderTraversal(void (*visit) (T &item)) const;
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

        binaryTree(const binaryTree<T> &otherTree);
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

        void inorder(node<T> *p, void (*visit) (T &item)) const;
            //Function to do an inorder traversal of the binary tree to which p points.
            //Postcondition: Nodes of the binary tree, to which p points, are printed
            //               in inorder sequence.

        void preorder(node<T> *p, void (*visit) (T &item)) const;
            //Function to do a preorder traversal of the binary tree to which p points.
            //Postcondition: Nodes of the binary tree, to which p points, are printed
            //               in preorder sequence.

        void postorder(node<T> *p, void (*visit) (T &item)) const;
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

template <class T>
bool binaryTree<T>::isEmpty() const {
    return(root == nullptr);
}

template <class T>
binaryTree<T>::binaryTree(){
    root = nullptr;
}

template <class T>
void binaryTree<T>::inorderTraversal(void (*visit) (T &item)) const {
    inorder(root, *visit);
}

template <class T>
void binaryTree<T>::preorderTraversal(void (*visit) (T &item)) const {
    preorder(root, *visit);
}

template <class T>
void binaryTree<T>::postorderTraversal(void (*visit) (T &item)) const {
    postorder(root, *visit);
}

template <class T>
int binaryTree<T>::treeHeight() const {
    return height(root);
}

template <class T>
void binaryTree<T>::inorder(node<T> *p, void (*visit) (T &item)) const {
    if(p != nullptr){
        inorder(p->lLink, *visit);
        (*visit)(p->data);
        inorder(p->rLink, *visit);
    }
}

template <class T>
void binaryTree<T>::preorder(node<T> *p, void (*visit) (T &item)) const {
    if(p != nullptr){
        (*visit)(p->data);
        preorder(p->lLink, *visit);
        preorder(p->rLink, *visit);
    }
}

template <class T>
void binaryTree<T>::postorder(node<T> *p, void (*visit) (T &item)) const {
    if(p != nullptr){
        postorder(p->lLink, *visit);
        postorder(p->rLink, *visit);
        (*visit)(p->data);
    }
}

template <class T>
int binaryTree<T>::height(node<T> *p) const {
    if(p == nullptr)
        return 0;
    else
    {
        return 1 + max(height(p->lLink), height(p->rLink));
    } 
}

template <class T>
int binaryTree<T>::max(int x, int y) const{
    if(x >= y)
        return x;
    else
        return y;
}

template <class T>
void binaryTree<T>::copyTree(node<T> *&copiedTreeRoot, node<T> *otherTreeRoot){
    if(otherTreeRoot == nullptr)
        copiedTreeRoot = nullptr;
    else
    {
        copiedTreeRoot = new node<T>;
        copiedTreeRoot->data = otherTreeRoot->data;
        copyTree(copiedTreeRoot->lLink, otherTreeRoot->lLink);
        copyTree(copiedTreeRoot->rLink, otherTreeRoot->rLink);
    }
}

template <class T>
void binaryTree<T>::destroy(node<T> *&p){
    if(p != nullptr){
        destroy(p->lLink);
        destroy(p->rLink);
        delete p;
        p = nullptr;
    }
}

template <class T>
void binaryTree<T>::destroyTree(){
    destroy(root);
}

template <class T>
binaryTree<T>::binaryTree(const binaryTree<T> &otherTree){
    if(otherTree.root == nullptr) //otherTree is empty
        root = nullptr;
    else
    {
            copyTree(root, otherTree.root);
    }
    
}

template <class T>
binaryTree<T>::~binaryTree(){
    destroy(root);
}

template <class T>
const binaryTree<T> &binaryTree<T>::operator=(const binaryTree<T> &otherTree){
    if(this != &otherTree){  //avoid self copy
        if(root != nullptr) //if the binary tree isn't empty, destroy the binary tree
            destroy(root);
        if(otherTree.root == nullptr) //otherTree is empty
            root = nullptr;
        else
        {
                copyTree(root, otherTree.root);
        }
        
    }
    return *this;
}

template <class T>
int binaryTree<T>::treeNodeCount() const {
    return nodeCount(root);
}

template <class T>
int binaryTree<T>::nodeCount(node<T> *p) const{
    if(p == nullptr)
        return 0;
    else
    {
        return 1 + nodeCount(p->lLink) + nodeCount(p->rLink);
    }  
}

template <class T>
int binaryTree<T>::treeLeavesCount() const {
    return leavesCount(root);
}

template <class T>
int binaryTree<T>::leavesCount(node<T> *p) const{
    if(p == nullptr)
        return 0;
    else if(p->lLink == nullptr && p->rLink == nullptr)
        return 1;
    else{
        return leavesCount(p->lLink) + leavesCount(p->rLink);
    }
}

#endif