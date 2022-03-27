#include "common.h"


void insertSort(int arry[], int length)
{
    for (int i = 1; i < length; i++) {
        for (int j = i-1; j >= 0; j--) {
            if (arry[j+1] < arry[j]) {
                swapNumber(arry[j], arry[j+1]);
            } else {
                break;
            }
        }
    }
}


void insertSort2(int arry[], int length)
{
    for (int i = 1; i < length; i++) {
        int insertValue = arry[i];
        int j = i - 1;
        while(j >= 0 && arry[j] > insertValue) {
            arry[j+1] = arry[j];  // 数组右移，腾位置插入
            j--;
        }
        arry[j+1] = insertValue;
    }
}


void bubbleSort(int arry[], int length)
{
    for (int i = 0; i < length; length--) {
        for (int j = 0; j+1 < length-i; j++) {
            if (arry[j] > arry[j+1]) {
                swapNumber(arry[j], arry[j+1]);
            }
        }
    }
}


void selectSort(int arry[], int length)
{
    for (int i = 0; i < length-1; i++) {
        int minIndex = i;
        for(int j = i+1; j< length; j++) {
            if (arry[j] < arry[minIndex]) {
                minIndex = j;
            }
        }
        swapNumber(arry[i], arry[minIndex]);
    }
}