#include "common.h"

void arryMerge(int arry[], int left, int mid, int end);


void mergeSort(int *arry, int length)
{
    if (length == 1) {
        return;
    }

    int mid = length/2;
    mergeSort(arry, mid);
    mergeSort(arry+mid, length - mid);
    arryMerge(arry, 0, mid, length-1);
}


void arryMerge(int arry[], int left, int mid, int end)
{
    int *res = new int[end-left+1];
    int i = 0;
    int p1 = left;
    int p2 = mid;
    while (p1 < mid && p2 <= end) {
        res[i++] = arry[p1] < arry[p2] ? arry[p1++] : arry[p2++];
    }
    
    while (p1 < mid) {
        res[i++] = arry[p1++];
    }

    while (p2 <= end) {
        res[i++] = arry[p2++];
    }

    for (size_t i = 0; i <= end; i++) {
        arry[i] = res[i];
    }
    delete [] res;
    res = NULL;
}
