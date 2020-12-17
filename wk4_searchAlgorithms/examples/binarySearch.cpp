/************************************
 *  Author: Eric Johnson
 *  Date:   11/30/2020
 * 
 *  Grantham University
 *  CS325 Data Structures
 *  Week 3: Sorting Algorithms
 * 
 *  This is an example from the text of a binary search algorithm.
 *  ***********************************/

template <class T>
int binarySearch(const T list[], int length, const T &item){

    int first = 0;
    int last = length -1;
    int mid;

    bool found = false;

    while(first <= last && !found){
        mid = (first + last) / 2;

        if(list[mid] == item)
            found = true;
        else if(list[mid] > item)
            last = mid -1;
        else
        {
            first = mid + 1;
        }
    }
    if(found)
        return mid;
    else
    {
        return -1;
    }
        
}