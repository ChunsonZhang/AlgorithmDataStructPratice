#include "common.h"

int minHeapInsert(int arry[], int length, int heapSize, int insertVal)
{
    if (heapSize >= length) {
        return -1;
    }

    arry[heapSize++] = insertVal;
    int sonNode = heapSize-1;

    while (arry[(sonNode-1)/2] > arry[sonNode]) {
        swapNumber(arry[(sonNode-1)/2], arry[sonNode]);
        sonNode = (sonNode-1)/2;
    }
    return 0;
}


int maxHeapInsert(int arry[], int length, int heapSize, int insertVal)
{
    if (heapSize >= length) {
        return -1;
    }

    arry[heapSize++] = insertVal;
    int sonNode = heapSize-1;

    while (arry[(sonNode-1)/2] < arry[sonNode]) {
        swapNumber(arry[(sonNode-1)/2], arry[sonNode]);
        sonNode = (sonNode-1)/2;
    }
    return 0;
}


int minHeapify(int arry[], int heapSize, int heapifyIndex)
{
    if (heapifyIndex >= heapSize) {
        return -1;
    }

    int leftSon = heapifyIndex * 2 + 1;
    int rightSon = heapifyIndex * 2 + 2;
    int minNode = 0;
    while (leftSon < heapSize) {
        minNode = (rightSon < heapSize && arry[rightSon] < arry[leftSon]) ? rightSon : leftSon;
        if (arry[minNode] >= arry[heapifyIndex]) {
            break;
        }
        
        swapNumber(arry[heapifyIndex], arry[minNode]);

        heapifyIndex = minNode;
        leftSon = heapifyIndex * 2 + 1;
        rightSon = heapifyIndex * 2 + 2;
    }
    return 0;
}


int maxHeapify(int arry[], int heapSize, int heapifyIndex)
{
    if (heapifyIndex >= heapSize) {
        return -1;
    }

    int leftSon = heapifyIndex * 2 + 1;
    int rightSon = heapifyIndex * 2 + 2;
    int maxNode = 0;
    while (leftSon < heapSize) {
        maxNode = (rightSon < heapSize && arry[rightSon] > arry[leftSon]) ? rightSon : leftSon;
        if (arry[maxNode] <= arry[heapifyIndex]) {
            break;
        }
        
        swapNumber(arry[heapifyIndex], arry[maxNode]);

        heapifyIndex = maxNode;
        leftSon = heapifyIndex * 2 + 1;
        rightSon = heapifyIndex * 2 + 2;
    }
    return 0;
}


static void builMinHeap(int arry[], int length) 
{
    for (int i = length - 1; i >= 0; i--) {
        minHeapify(arry, length, i);
    }
}


static void builMaxHeap(int arry[], int length)
{
    for (int i = length - 1; i >= 0; i--) {
        maxHeapify(arry, length, i);
    }
}


void minHeapSort(int arry[], int length)
{
    builMaxHeap(arry, length);
    for (int i = 0; i < length-1; i++) {
        swapNumber(arry[0], arry[length-1-i]);
        maxHeapify(arry, length-i-1, 0);
    }
}