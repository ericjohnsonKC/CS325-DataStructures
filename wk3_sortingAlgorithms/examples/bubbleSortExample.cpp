/************************************
 *  Author: Eric Johnson
 *  Date:   11/30/2020
 * 
 *  Grantham University
 *  CS325 Data Structures
 *  Week 3: Sorting Algorithms
 * 
 *  This is an example from the text of a bubble sort algorithm.
 *  ***********************************/

template <class elem>
void bubbleSort(elem list[], int length){
    for(int i = 1; i < length; i++){
        for(int index = 0; index < length - i; index++){
            if(list[index] > list[index + 1]){
                elem temp = list[index];
                list[index] = list[index + 1];
                list[index + 1] = temp;
            }
        }
    }
}