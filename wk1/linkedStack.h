/*********************************
*   Author: Eric Johnson
*   Date: 7/13/2020
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



#endif