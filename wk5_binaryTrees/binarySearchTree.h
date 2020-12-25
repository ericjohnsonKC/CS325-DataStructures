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
*   search tree abstract class. It extends the binary 
*   tree class.
*************************************/

#ifndef bsearchTree_h
#define bsearchTree_h

#include "binaryTreeADT.h"
#include <iostream>

template <class T>
class bSearchTree: public binaryTree<T>{
    public:
        bool search(const T &searchItem) const;
            //Function to determine if searchItem is in the binary 
            //search tree.
            //Postcondition: Returns true if searchItem is found in the 
            //               binary search tree; otherwise returns false.

        void insert(const T &insertItem);
            //Function to insert insertItem in the binary search tree.
            //Postcondition: If there is no node in the binary search
            //               tree that has the same info as insertItem,
            //               a node with the info insertItem is created
            //               and inserted in the binary search tree.

        void deleteNode(const T &deleteItem);
            //Function to delete deleteItem from the binary search tree
            //Postcondition: If a node with the same info as deleteItem
            //               is found, it is deleted from the binary search
            //               tree.  If the binary tree is empty of deleteItem
            //               is not in the binary tree, an appropriate message
            //               is printed.
    private:
        void deleteFromTree(node<T> *&p);
            //Function to delete the node to which p points is deleted from 
            //the binary search tree.
            //Postcondition: The node to which p points is deleted from the 
            //binary search tree.
};

template <class T>
bool bSearchTree<T>::search(const T &searchItem) const{
    node<T> *current;
    bool found = false;

    if(this->root == nullptr)
        std::cout << "Cannot search an empty tree." << std::endl;
    else{
        current = this->root;

        while(current != nullptr && !found){
            if(current->data == searchItem)
                found = true;
            else if(current->data > searchItem)
                current = current->lLink;
            else{
                current = current->rLink;
            }                        
        }
    }

    return found;
}

template <class T>
void bSearchTree<T>::insert(const T &insertItem){

    node<T> *current;  //pointer to traverse the tree
    node<T> *trailCurrent = nullptr;  //pointer behind current
    node<T> *newNode;  //pointer to create the node

    newNode = new node<T>;
    newNode->data = insertItem;
    newNode->lLink = nullptr;
    newNode->rLink = nullptr;

    if(this->root == nullptr)
        this->root = newNode;
    else{
        current = this->root;

        while(current != nullptr){
            trailCurrent = current;

            if(current->data == insertItem){
                std::cout << "The item to be inserted is already ";
                std::cout << "in the tree -- duplicates are not "
                     << "allowed." << std::endl;
                return;
            }
            else if(current->data > insertItem)
                current = current->lLink;
            else{
                current = current->rLink;
            }            
        }

        if (trailCurrent->data > insertItem)
            trailCurrent->lLink = newNode;
        else{
            trailCurrent->rLink = newNode;
        }       
    }
}

template <class T>
void bSearchTree<T>::deleteFromTree(node<T> *&p){

    node<T> *current;  //pointer to traverse the tree
    node<T> *trailCurrent; //pointer behind current
    node<T> *temp;  //pointer to delete the node

    if(p == nullptr)
        std::cout << "Error: The node to be deleted does not exist."
             << std::endl;
    else if(p->lLink == nullptr && p->rLink == nullptr){
        temp = p;
        p = nullptr;
        delete temp;
    }
    else if(p->lLink == nullptr){
        temp = p;
        p = temp->rLink;
        delete temp;
    }
    else if(p->rLink == nullptr){
        temp = p;
        p = temp->lLink;
        delete temp;
    }
    else{
        current = p->lLink;
        trailCurrent = nullptr;

        while(current->rLink != nullptr){
            trailCurrent = current;
            current = current->rLink;
        }

        p->data = current->data;

        if(trailCurrent == nullptr)
            p->lLink = current->lLink;
        else
            trailCurrent->rLink = current->lLink;
        delete current;
    }
}

template <class T>
void bSearchTree<T>::deleteNode(const T &deleteItem){
    
    node<T> *current;  //pointer to traverse the tree
    node<T> *trailCurrent; //pointer behind current
    bool found = false;

    if(this->root == nullptr)
        std::cout << "Cannot delete from an empty tree." << std::endl;
    else{
        current = this->root;
        trailCurrent = this->root;

        while(current != nullptr && !found){
            if(current->data == deleteItem)
                found = true;
            else{
                trailCurrent = current;
                if(current->data > deleteItem)
                    current = current->lLink;
                else{
                    current = current->rLink;
                }  
            }
        }

        if (current == nullptr)
            std::cout << "The item to be deleted is not in the tree." << std::endl;
        
        else if(found){
            if(current == this->root)
                deleteFromTree(this->root);
            else if(trailCurrent->data > deleteItem){
                deleteFromTree(trailCurrent->lLink);
            }
            else{
                deleteFromTree(trailCurrent->rLink);
            }
        }
        else{
            std::cout << "The item to be deleted is not in the tree." << std::endl;
        }
    }
}
#endif