#include <stdio.h>
#include "common.h"
#include "singleList.h"

void mergeSort(int *arry, int length);
void quickSort(int arry[], int left, int right);
void insertSort(int arry[], int length);
void insertSort2(int arry[], int length);
void bubbleSort(int arry[], int length);
void selectSort(int arry[], int length);
void minHeapSort(int arry[], int length);
int arrySortTestCase(void);
void partitionLinkListTestCase(void);


int main()
{
    int length = 0;
    // for (size_t i = 0; i < 10000; i++)
    // {
    //     int *arry = generateArry(&length);
    //     // scanf("%d", &length);
    //     // int *arry = generateOrderArry(length);
    //     arrySortTestCase(arry, length);

    //     getMidNodeTestCase(arry, length);
    //     delete [] arry;
    // }

    arrySortTestCase();
    // partitionLinkListTestCase();
    std::cout << "test finish." << std::endl;
    return 0;
}


int arrySortTestCase(void)
{
    int length = 0;
    int* arry0 = generateArry(&length, 0, 100);
    int* arry[6];
    for (int i = 0; i < 6; i++) {
        arry[i] = new int[length];
    }

    for (int i = 0; i < 6; i++) {
        for (size_t j = 0; j < length; j++) {
            arry[i][j] = arry0[j];
        }
    } 

    mergeSort(arry[0], length);
    quickSort(arry[1], 0, length-1);
    insertSort(arry[2], length);
    bubbleSort(arry[3], length);
    insertSort2(arry[4], length);
    minHeapSort(arry[5], length);

    std::vector<int> arryVec(arry0, arry0+length);
    std::sort(arryVec.begin(), arryVec.end());

    for (size_t i = 0; i < length; i++) {
        for (int j = 0; j < 6; j++) {
            if (arry[j][i] != arryVec[i]) {
                std::cout << "arry" << j << "sort failed" << std::endl;
                return -1;
            }
        }
    }

    for (int i = 0; i < 6; i++) {
        delete [] arry[i];
        arry[i] = NULL;
    }
    return 0;
}


void echoLinkListTestCase(void)
{
    int arry1[] = {1,2,3,2,1};
    int arry2[] = {1,2,3,4, 4,3,2,1};
    int arry3[] = {1,2,3,4,3,2,1};
    int arry4[] = {1,2,3,4,3,2,5};
    int arry5[] = {1,2,3,0,3,2,1};
    
    testEchoLinkList(arry1, 5);
    std::cout << std::endl;
    testEchoLinkList(arry2, 8);
    std::cout << std::endl;
    testEchoLinkList(arry3, 7);
    std::cout << std::endl;
    testEchoLinkList(arry4, 7);
    std::cout << std::endl;
    testEchoLinkList(arry5, 7);
}


void partitionLinkListTestCase(void)
{
    int length = 0;
    NoHeadSingleList_t *list = NULL;
    for (size_t i = 0; i < 1; i++) {
        
        int *arry = generateArry(&length, 0, 20);
        list = createNoheadSingleList(arry, length);
        showEachNodeOfSingleList(list);
        if (!list) {
            printf("Create link list failed\n");
            return;
        }

        // list->head = partitionLinkList(list->head, 19);
        list->head = partitionLinkListUseArry(list->head, 10);
        showEachNodeOfSingleList(list);

        delete [] arry;
        destroySingleList(list);
        list = NULL;
    }
}