/*****************************************
 *  Author: Eric Johnson
 *  Date: 12/26/2020
 * 
 *  Grantham University
 *  CS325 Data Structures
 * 
 *  Week 6: Graphs
 * 
 *  This file is a class header for a linkedQueueType.
 * ******************************************/

#include "queueADT.h"

#include <cassert>

template<class T>
struct node{
    T data;
    node<T> *link;
};

template<class T>
class linkedQueueType: public queueADT<T>{
    public:
        const linkedQueueType<T> & operator = (const linkedQueueType<T>&);
            //Overload the assignment operator.

        bool isEmptyQueue() const;
            //Function to determine whether the queue is empty.
            //Postcondition: Returns true if the queue is empty, 
            //               otherwise returns false.

        bool isFullQueue() const;
            //Function to determine whether the queue is full.
            //Postcondition: Returns true if the queue if full,
            //               otherwise returns false.

        void initializeQueue();
            //Function to initialize the queue to an empty state.
            //Postcondition: queueFront = nullptr; queueRear = nullptr

        T front() const;
            //Function to return the first element of the queue.
            //Precondition: The queue exists and is not empty.
            //Postcondition: If the queue is empty, the program
            //               terminates; otherwise the first element
            //               of the queue is returned.
        
        T back() const;
            //Function to return the last element of the queue.
            //Precondition: The queue exists and is not empty.
            //Postcondition: If the queue is empty, the program terminates;
            //               otherwise, the last element of the queue is returned.

        void enQueue(const T & queueElement);
            //Function to add queueElement to the queue.
            //Precondition: The queue exists and is not full.
            //Postcondition: The queue is changed and queueElement is added 
            //               to the queue.
        
        void deQueue();
            //Function to remove the first element of the queue.
            //Precondition: The queue exists and is not empty.
            //Postcondition: The queue is changed and the first element is 
            //               removed from the queue.
        
        linkedQueueType();
            //Default constructor
        
        linkedQueueType(const linkedQueueType<T> & otherQueue);
            //Copy constructor
        
        ~linkedQueueType();
            //Destructor
    
    private:
        node<T> * queueFront; //pointer to the front of the queue
        node<T> * queueRear;  //pointer to the rear of the queue
};

template<class T>
bool linkedQueueType<T>::isEmptyQueue() const{
    return(queueFront == nullptr);
}

template<class T>
bool linkedQueueType<T>::isFullQueue() const{
    return false;
}

template<class T>
void linkedQueueType<T>::initializeQueue(){
    node<T> * temp;

    while(queueFront != nullptr){ //while there are elements left in the queue
        
        temp = queueFront; //set temp to point to the current node

        queueFront = queueFront->link;  //advance first to the next node

        delete temp; //deallocate memory occupied by temp
    }

    queueRear = nullptr; //set rear to nullptr
}

template<class T>
void linkedQueueType<T>::enQueue(const T & newElement){
    node<T> * newNode;

    newNode = new node<T>; //create the node

    newNode->data = newElement;  //store the data
    newNode->link = nullptr; //initialize the link field to nullptr

    if(queueFront == nullptr){ //if initially the queue is empty
        queueFront = newNode;
        queueRear = newNode;
    }
    else{   //add newNode at the end
        queueRear->link = newNode;
        queueRear = queueRear->link;
    }
}

template<class T>
T linkedQueueType<T>::front() const{
    assert(queueFront != nullptr);
    return queueFront->data;
}

template<class T>
T linkedQueueType<T>::back() const{
    assert(queueRear != nullptr);
    return queueRear->data;
}

template<class T>
void linkedQueueType<T>::deQueue(){
    node<T> * temp;

    if(!isEmptyQueue()){
        temp = queueFront; //make temp point to the first node
        
        queueFront = queueFront->link; //advance queueFront

        delete temp; //delete the first node

        if(queueFront == nullptr) //if after deletion the queue is empty
            queueRear = nullptr;  //set queueRear to nullptr
    }
    else{
        std::cout << "Cannot remove from an empty queue" << std::endl;
    }
}

template<class T>
linkedQueueType<T>::linkedQueueType(){
    queueFront = nullptr; //set front to nullptr
    queueRear = nullptr; //set rear to nullptr
}

template<class T>
linkedQueueType<T>::linkedQueueType(const linkedQueueType<T> & otherQueue){
    //****************************write code here******************************************************
}

template<class T>
linkedQueueType<T>::~linkedQueueType(){
    //****************************write code here******************************************************
}