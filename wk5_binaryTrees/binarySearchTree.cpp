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
*   This file is the implementation file for a binary 
*   search tree class. It extends the binaryTreeADT
*   class.
*************************************/

#include "binaryTreeADT.h"
#include "binarySearchTree.h"

#include <iostream>

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