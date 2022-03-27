#include "common.h"

void arryPartition(
        int arry[], int left, int right, 
        int &resleft, int &resRight);


void quickSort(int arry[], int left, int right)
{
    static uint64_t i = 0;
    if (left >= right) {
        return;
    }

    int randswap = rand() % (right-left+1) + left;
    swapNumber(arry[randswap], arry[right]);

    int resLeft = 0, resRight = 0;
    arryPartition(arry, left, right, resLeft, resRight);
    quickSort(arry, left, resLeft-1);
    quickSort(arry, resRight+1, right);
}


void arryPartition(int arry[], int left, int right, int &resleft, int &resRight)
{
    int leftIndex = left;
    int rightIndex = right;
    int compareNum = arry[right];

    int i =  left;
    while(i <= rightIndex) {
        if (arry[i] < compareNum) {
            swapNumber(arry[i], arry[leftIndex]);
            leftIndex++;
            i++;
        } else if (arry[i] > compareNum) {
            swapNumber(arry[i], arry[rightIndex]);
            rightIndex--;
        } else {
            i++;
        }
    }

    resleft = leftIndex;
    resRight = rightIndex;
}