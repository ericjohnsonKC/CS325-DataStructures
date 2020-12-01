/************************************
 *  Author: Eric Johnson
 *  Date:   11/30/2020
 * 
 *  Grantham University
 *  CS325 Data Structures
 *  Week 3: Sorting Algorithms
 * 
 *  This is an example from the text of a selection sort algorithm.
 *  ***********************************/

template <class T>
int minLocation(T list[], int first, int last){
    int minIndex;

    minIndex = first;

    for(int loc = first + 1; loc <= last; loc++)
        if(list[loc] < list[minIndex])
            minIndex = loc;

    return minIndex;
}

template <class T>
void swap(T list[], int first, int second){
    T temp;

    temp = list[first];
    list[first] = list[second];
    list[second] = temp;
}

template <class T>
void selectionSort(T list[], int length){
    int minIndex;

    for(int loc = 0; loc < length; loc++){
        minIndex = minLocation(list, loc, length - 1);
        swap(list, loc, minIndex);
    }
}