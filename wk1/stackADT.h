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

template<typename T>
class stackADT
{
    public:
        virtual void intitializeStack() = 0;
            // Method to initialize stack to empty state.

        virtual bool isEmptyStack() const = 0;
            // Function to determine whether the stack is empty.

        virtual bool isFullStack() const = 0;
            // Function to determine whether the stack is full.

        virtual void push(const T & newItem) = 0;
            // Function to add newItem to the stack.

        virtual T top() const = 0;
            // Function to return the top element of the stack.
        
        virtual void pop() = 0;
            // Function to remove the top element of the stack.
};