/************************************
 *  Author: Eric Johnson
 *  Date:   11/30/2020
 * 
 *  Grantham University
 *  CS325 Data Structures
 *  Week 3: Sorting Algorithms
 * 
 *  This is an example from the text of a merge sort algorithm.
 *  ***********************************/

#include "unorderedLinkedList.h"

template <class T>
void unorderedLinkedList<T>::divideList(nodeType<T> *first1, nodeType<T> *&first2){
    nodeType<T> *middle;
    nodeType<T> *current;

    if(first1 == nullptr)  // list is empty
        first2 = nullptr;
    else if(first1->link == nullptr)  // list has only one node
        first2 = nullptr;
    else{
        middle = first1;
        current = first1->link;

        if(current != nullptr)  // list has more than two nodes
            current = current->link;

        while(current != nullptr){
            middle = middle->link;
            current = current->link;
            if (current != nullptr)
                current = current->link;
        }

        first2 = middle->link;  //first2 points to the first node of the second sublist

        middle->link = nullptr;  //set the link of the last node of the first sublist to nullptr
    }
}

template <class T>
nodeType<T> *unorderedLinkedList<T>::mergeList(nodeType<T> *first1, nodeType<T> *first2){
    nodeType<T> *lastSmall;  //pointer to the last node of the merged list
    nodeType<T> *newHead;   //pointer to the merged list

    if(first1 == nullptr)  //the first sublist is empty
        return first2;
    else if(first2 == nullptr) //the second sublist is empty
        return first1;
    else{
        if(fist1->info < first2->info){  //compare the first nodes - note: may need to overload comparison operator
            newHead = first1;
            first1 = first1->link;
            lastSmall = newHead;
        }
        else{
            newHead = first2;
            first2 = first2->link;
            lastSmall = newHead;
        }
        while(first1 != nullptr && first2 != nullptr){
            if(first1->info < first2->info){
                lastSmall->link = first1;
                lastSmall = lastSmall->link;
                first1 = first1->link;
            }
            else{
                lastSmall->link = first2;
                lastSmall = lastSmall->link;
                first2 = first2->link;
            }
        }

        if(first1 == nullptr) //first sublist exhausted first
            lastSmall->link = first2;
        else        //second sublist exhausted first
            lastSmall->link = first1;
        
        return newHead;
    }
}

template <class T>
void unorderedLinkedList<T>::recursiveMergeSort(nodeType<T> *&head){
    nodeType<T> *otherHead;

    if(head != nullptr)  //if the list is not empty
        if(head->link != nullptr){  //if the list has more than one node
            divideList(head, otherHead);
            recursiveMergeSort(head);
            recursiveMergeSort(otherHead);
            head = mergeList(head, otherHead);
        }

}