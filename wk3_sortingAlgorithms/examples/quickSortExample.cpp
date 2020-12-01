/************************************
 *  Author: Eric Johnson
 *  Date:   11/30/2020
 * 
 *  Grantham University
 *  CS325 Data Structures
 *  Week 3: Sorting Algorithms
 * 
 *  This is an example from the text of a quick sort algorithm.
 *  ***********************************/


template <class T>
void swap(T list[], int first, int second){
    T temp;

    temp = list[first];
    list[first] = list[second];
    list[second] = temp;
}

template <class T>
int partition(T list[], int first, int last){
    T pivot;

    int smallIndex;

    swap(list, first, (first + last) / 2);

    pivot = list[first];
    smallIndex = first;

    for(int index = first + 1; index <= last; index++)
        if(list[index] < pivot){
            smallIndex++;
            swap(list, smallIndex, index);
        }
    swap(list, first, smallIndex);

    return smallIndex;
}

template <class T>
void recursiveQuickSort(T list[], int first, int last){
    int pivotLocation;

    if(first < last){
        pivotLocation = partition(list, first, last);
        recursiveQuickSort(list, first, pivotLocation -1);
        recursiveQuickSort(list, pivotLocation +1, last);
    }
}

template <class T>
void quickSort(T list[], int length){
    recursiveQuickSort(list, 0, length - 1);
}