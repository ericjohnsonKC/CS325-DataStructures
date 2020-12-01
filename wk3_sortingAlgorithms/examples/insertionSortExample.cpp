/************************************
 *  Author: Eric Johnson
 *  Date:   11/30/2020
 * 
 *  Grantham University
 *  CS325 Data Structures
 *  Week 3: Sorting Algorithms
 * 
 *  This is an example from the text of an insertion sort algorithm.
 *  ***********************************/

template <class T>
void insertionSort(T list[], int length){
    for(int firstOutOfOrder = 1; firstOutOfOrder < length; firstOutOfOrder++)
        if(list[firstOutOfOrder] < list[firstOutOfOrder - 1]){
            T temp = list[firstOutOfOrder];
            int location = firstOutOfOrder;

            do{
                list[location] = list[location - 1];
                location--;
            }
            while(location > 0 && list[location - 1] > temp);

            list[location] = temp;
        }
}