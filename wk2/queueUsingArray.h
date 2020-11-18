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
 *  This file will define an implementation of a queue using an array.
 *  I chose the array approach because a linked list was used for the 
 *  prior assignment on stacks, and I believe implementing a circular
 *  array is challenging enough to warrant going thru the exercise.
 * ***********************************/

#include "queueADT.h"

#include <cassert>

using namespace std;

template <typename T>
class queueUsingArray: public queueAbstractClass<T>
{
    public:
        const queueUsingArray<T>& operator=(const queueUsingArray<T>&);
            //Overload the assignment operator
        
        bool isEmptyQueue() const;
            //Function to determine whether the queue is empty.
            //Postcondition: Returns true if the queue is empty,
            //  othewise returns false.
        
        bool isFullQueue() const;
            //Function to determine whether the queue is full.
            //Postcondition: Returns true if the queue is full,
            //  otherwise returns false.

        void initializeQueue();
            //Function to initialize the queue to an empty state.
            //Postcondition: The queue is empty.

        T front() const;
            //Function to return the first element of the queue.
            //Precondition: The queue exists and is not empty.
            //Postcondition: If the queue is empty, the program
            //  terminates; otherwise the first element of the 
            //  queue is returned.

        T back() const;
            //Function to return the last element of the queue.
            //Precondition: The queue exists and is not empty.
            //Postcondition: If the queue is empty, the program
            //  terminates; otherwise the last element of the 
            //  queue is returned.

        void addQueue(const T& queueElement);
            //Function to add queueElement to the queue.
            //Precondition: The queue exists and is not full.
            //Postcondition: The queue is changed and queueElement
            //  is added to the queue.
        
        void deleteQueue();
            //Function to remove the first element of the queue.
            //Precondition: The queue exists and is not empty.
            //Postcondition: The queue is changed and the first 
            //  element is removed from the queue.

        queueUsingArray(int queueSize = 100);
            //Constructor
        
        queueUsingArray(const queueUsingArray<T>& otherQueue);
            //Copy constructor

        ~queueUsingArray();
            //Destructor

    private:
        int maxQueueSize;   //variable to store the max queue size
        int count;          //variable to store the number of 
                            //elements in the queue
        int queueFront;     //variable to point to the first
                            //element of the queue
        int queueRear;      //variable to point to the last
                            //element of the queue
        T *list;            //pointer to the array that holds the 
                            //queue elements
};

/********************************************
 *  Member function definitions
 * *****************************************/


template<typename T>
const queueUsingArray<T>& queueUsingArray<T>::operator=(const queueUsingArray<T>& otherQueue) {
    if(this != &otherQueue){       // Avoid a self copy
        if(!this->isEmptyQueue){        //If queue isn't empty, initialize it
            this->initializeQueue();

            //This function needs to be completed
        }
    }  

}

template<typename T>
bool queueUsingArray<T>::isEmptyQueue() const {
    return (count == 0);   // If count is zero, queue is empty
}

template<typename T>
bool queueUsingArray<T>::isFullQueue() const {
    return (count == maxQueueSize);  // If count == maxQueueSize, 
                                     // then queue is full
}

template<typename T>
void queueUsingArray<T>::initializeQueue() {
    queueFront = 0;                   // Sets the queue to a ready state
    queueRear = maxQueueSize - 1;
    count = 0;
}

template<typename T>
T queueUsingArray<T>::front() const {
    assert(!isEmptyQueue());
    return list[queueFront];
}

template<typename T>
T queueUsingArray<T>::back() const {
    assert(!isEmptyQueue());
    return list[queueRear];
}

template<typename T>
void queueUsingArray<T>::addQueue(const T & newElement) {
    if (!isFullQueue()) {
        queueRear = (queueRear + 1) % maxQueueSize;  // This makes the queue
        count++;                                     // array circular.
        list[queueRear] = newElement;
    }
    else
    {
        cout << "Cannot add to a full queue." << endl;
    }
}

template<typename T>
void queueUsingArray<T>::deleteQueue(){
    if (!isEmptyQueue()) {
        count--;
        queueFront = (queueFront + 1) % maxQueueSize;  //This makes the queue array
    }                                                  //circular.
}

template<typename T>
queueUsingArray<T>::queueUsingArray(int queueSize) {
    if (queueSize <= 0){
        cout << "Size of the array to hold the queue must be positive." << endl;
        cout << "Creating an array of size 100." << endl;

        maxQueueSize = 100;
    }
    else
    {
        maxQueueSize = queueSize;   //Set maxQueueSize to queueSize
        queueFront = 0;             //initialize queueFront
        queueRear = maxQueueSize -1 //initialize queueRear
        count = 0;
        list = new T[maxQueueSize]; //create the array to hold queue elements
    }
}

template<typename T>
queueUsingArray<T>::~queueUsingArray(){
    delete [] list;
}
