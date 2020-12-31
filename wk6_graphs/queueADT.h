/************************************
 *  Author: Eric Johnson
 *  Date:   11/17/2020
 * 
 *  Grantham University
 *  CS325 Data Structures
 *  Week 2: Queues
 * 
 *  This assignment is to create a queue data structure
 *  given the instructions.
 * 
 *  This file will define an abstract class for a queue.
 * ***********************************/

#ifndef queueAbstractClass_H
#define queueAbstractClass_H

template <typename T>
class queueAbstractClass
{
    public:
        virtual bool isEmptyQueue() const = 0;
            //Function to determine whether queue is empty.
            //Postcondition: Returns true if the queue is empty,
            //  otherwise returns false.

        virtual bool isFullQueue() const = 0;
            //Function to determine whethere queue is full.
            //Postcondition: Returns true if the queue is full,
            //  otherwise returns false.

        virtual void initializeQueue() = 0;
            //Function to initialize the queue to an empty state.
            //Postcondition: The queue is empty.

        virtual T front() const = 0;
            //Function to return the first element of the queue.
            //Precondition: The queue exists and is not empty.
            //Postcondition: If the queue is empty, the program 
            //  terminates; otherwise, the first element of the 
            //  queue is returned.

        virtual T back() const = 0; 
            //Function to return the last element of the queue.
            //Precondition: The queue exists and is not empty.
            //Postcondition: If the queue is empty, the progream
            //  terminates; otherwise, the last element of the queue
            //  is returned.

        virtual void enQueue(const T& queueElement) = 0;
            //Function to add queueElement to the queue.
            //Precondition: The queue exists and is not full.
            //Postcondition: The queue is changed and queueElement
            //  is added to the queue.

        virtual void deQueue() = 0;
            //Function to remove the first element of the queue.
            //Precondition: The queue exists and is not empty.
            //Postcondition: The queue is changed and the first element
            //  is removed from the queue.
};

#endif