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
*   This file is the implementation file for the 
*   binaryTreeADT abstract class.
*************************************/

#include "binaryTreeADT.h"

#include <iostream>

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
        inorder(p->lLink);
        (*visit)(p->data);
        inorder(p->rLink);
    }
}

template <class T>
void binaryTree<T>::preorder(node<T> *p, void (*visit) (T &item)) const {
    if(p != nullptr){
        (*visit)(p->data);
        preorder(p->lLink);
        preorder(p->rLink);
    }
}

template <class T>
void binaryTree<T>::postorder(node<T> *p, void (*visit) (T &item)) const {
    if(p != nullptr){
        postorder(p->lLink);
        postorder(p->rLink);
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
        return *this;
    }
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
        return 1 + count(p->lLink) + count(p->rLink);
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