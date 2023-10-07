#include "mySort.h"
#include <stdio.h>

void merge(int array[], unsigned int first, unsigned int mid, unsigned int last)
{
    int x1 = mid - first + 1;
    int x2 = last - mid;
    int left = 0;
    int right = 0;
    int merged = first;

    //temporary arrays when the original array is divided
    int tempL[x1];
    int tempR[x2];

    //copies orginal array data to temporary arrays
    for (int i = 0; i < x1; ++i)
    {
        myCopy(&array[first + i], &tempL[i]);
    }
    for (int j = 0; j < x2; ++j)
    {
        myCopy(&array[mid + 1 + j], &tempR[j]);
    }

    //merges the temporary arrays back into the original array
    while (left < x1 && right < x2)
    {
        if (myCompare(tempL[left], tempR[right]) <= 0)
        {
            myCopy(&tempL[left],&array[merged]);
            left++;
        }
        else
        {
            myCopy(&tempR[right], &array[merged]);
            right++;
        }
        merged++;
    }
    //merges remaining elements of the array divided to the left to the original array
    while (left < x1)
    {
        myCopy(&tempL[left++], &array[merged++]);
    }
    //merges remaining elements of the array divided to the right to the original array
    while (right < x2)
    {
        myCopy(&tempR[right++], &array[merged++]);
    }
}

void mySort(int array[], unsigned int first, unsigned int last)
{
    if (first < last)
    {
        int mid = (first + last) / 2;
        mySort(array, first, mid);
        mySort(array, mid + 1, last);
        merge(array, first, mid, last);
    }
}