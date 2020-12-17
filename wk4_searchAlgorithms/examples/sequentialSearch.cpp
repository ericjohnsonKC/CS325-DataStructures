/************************************
 *  Author: Eric Johnson
 *  Date:   11/30/2020
 * 
 *  Grantham University
 *  CS325 Data Structures
 *  Week 3: Sorting Algorithms
 * 
 *  This is an example from the text of a sequential search algorithm.
 *  ***********************************/

template <class T>
int seqSearch(const T list[], int length, const T &item){
    
    int loc;
    bool found = false;

    loc = 0;

    while(loc < length && !found)
        if(list[loc] == item)
            found = true;
        else
        {
            loc++;
        }
    if(found)
        return loc;
    else 
        return -1;      
}