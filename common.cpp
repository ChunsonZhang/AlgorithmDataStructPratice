#include "common.h"




int* generateArry(int *length, int minValue, int valueLimit)
{
    static unsigned cnt = 0;
    cnt++;
    time_t sysTime = time(NULL);
    srand((unsigned int) sysTime + cnt);

    *length = (rand()%20) + 10;
    // *length = (rand()%1000);
    int *arry = new int[*length];
    
    for (size_t i = 0; i < (*length); i++) {
        arry[i] = (rand()%valueLimit) + minValue;
    }
    return arry;
}


int* generateOrderArry(int length)
{
    int *arry = new int[length];
    
    for (size_t i = 0; i < (length); i++) {
        arry[i] = i;
    }
    return arry;
}
