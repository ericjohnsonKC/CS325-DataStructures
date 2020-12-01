/*********************************
*   Author: Eric Johnson
*   Date: 11/17/2020
*
*   Grantham University
*   CS325 Data Structures
*   
*   This file may be used in multiple assignments
*   for this course.  I'm following closely along
*   with the textbook example to create it, although
*   I may alter or expand it later in the course.
**************************************/

#ifndef linkedStack_h
#define linkedStack_h

#include "stackADT.h"

#include <iostream>
#include <cassert>

using namespace std;

/*  First, a node type must be created.  The 
*   stack will be composed of a linked list, 
*   and the linked list will consist of nodes,
*   each with a data property and a pointer to 
*   the next node in the list.
*/

template <typename T>
struct node
{
    T data;
    node<T> * link;
};
// End of node type definition

/* Now the linkedStack type will be defined.
*  It will consist of the nodes defined above.
*/

template<typename T>
class linkedStack: public stackADT<T>
{
    public:
        const linkedStack<T> & operator=(const linkedStack<T> &);
            //  Overloading the assignment operator.
        
        bool isEmptyStack() const;
            // Function to determine if stack is empty.

        bool isFullStack() const;
            // Function to determine if the stack is full.
            /*  Always returns false because this derived class
            *   will create a stack from a linked list.  This 
            *   method is required because it is declared as a 
            *   virtual function of the base class.
            */

        void initializeStack();
            // Function to initialize the stack to an empty state.

        void push(const T & newItem);
            // Function to add newItem to the stack.

        T peek() const;
            // Function to return the top element of the stack.

        int size() const;
            // Function to return the size of the stack (number of elements).

        void pop();
            // Function to remove the top element of the stack.

        linkedStack();
            // Default constructor

        linkedStack(const linkedStack<T> & otherStack);
            // Copy constructor

        ~linkedStack();
            // Destructor

    private:
        node<T> * stackTop;  // Pointer to the stack

        void copyStack(const linkedStack<T> & otherStack);
            // Function to make a copy of otherStack.

        int stackSize;
};

/* The following is the member function definitions for the 
*  linkedStack type created above.
*/

template <typename T>
const linkedStack<T> & linkedStack<T>::operator=(const linkedStack<T> & otherStack) {
    if (this != &otherStack)  // avoid a self copy
        copyStack(otherStack);

    return *this;
}

template<typename T>
bool linkedStack<T>::isEmptyStack() const {
    return (stackTop == nullptr);
}
    
template<typename T>
bool linkedStack<T>::isFullStack() const {
    return false;  // This is because the stack is built with a linked list and will never be full.
}

template<typename T>
void linkedStack<T>::initializeStack() {
    node<T> * temp;  // pointer to delete the node

    while (stackTop != nullptr) { // while there are elements in the stack
        temp = stackTop;    // set temp to point to the current node
        stackTop = stackTop->link;  // advance stackTop to the next node
        delete temp; // deallocate memory occupied by temp
    }

    stackSize = 0; // set stackSize to reflect an empty stack
}

template<typename T>
void linkedStack<T>::push(const T & newItem) {
    node<T> *newNode;  // pointer to create the new node
    newNode = new node<T>;  // create the node
    newNode->data = newItem;  // store newItem in the node
    newNode->link = stackTop;  // insert newNode before stackTop
    stackTop = newNode;  // set stackTop to point to the top node
    stackSize++; // increment the stack size
}
   
template<typename T>
T linkedStack<T>::peek() const {
    assert(stackTop != nullptr); // If stack is empty, terminate.

    return stackTop->data; // Returns the top element
}
    
template<typename T>
int linkedStack<T>::size() const {
    return stackSize;  // Returns the size of the stack.
}

template<typename T>
void linkedStack<T>::pop() {
    node<T> * temp; // pointer to deallocate memory
    if (stackTop != nullptr) {
        temp = stackTop;  // set temp to point to the top node
        stackTop = stackTop->link; // advance stackTop to the next node
        delete temp; // delete the top node
        stackSize--;  // decrement the stackSize property
    }
    else    
        cout << "Error: Cannot remove from an empty stack." << endl;
}

template<typename T>
linkedStack<T>::linkedStack() {
    stackTop = nullptr; // Set pointer to nullptr
    stackSize = 0;  // Initialize stackSize at zero
}
    
template<typename T>
linkedStack<T>::linkedStack(const linkedStack<T> & otherStack) {
    stackTop = nullptr;
    copyStack(otherStack);
}
    
template<typename T>
linkedStack<T>::~linkedStack() {
    initializeStack();
}


template<typename T>
void linkedStack<T>::copyStack(const linkedStack<T> & otherStack) {
    node<T> *newNode, *current, *last;  // Declare local variables
    
    if (stackTop != nullptr) // if the stack is nonempty, make it empty
        initializeStack();

    if (otherStack.stackTop == nullptr)
        stackTop = nullptr;  // if otherStack is empty, create an empty stack
    else {
        current = otherStack.stackTop; // set current to point to the stack to be copied
        // Following steps copy stackTop element of the stack:
        stackTop = new node<T>;  // Create the node
        stackTop->data = current->data; // Copy the data
        stackTop->link = nullptr;  // Set link to nullptr
        last = stackTop; // Set last to point to the node
        current = current->link;  // Set current to point to the next node
    

        // Copy the remaining stack
        while (current != nullptr) {
            newNode = new node<T>;
            
            newNode->data = current->data;
            newNode->link = nullptr;
            last->link = newNode;
            last = newNode;
            current = current->link;
        }
    }
}

#endif