#ifndef _COMMON_H_
#define _COMMON_H_

#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
void swapNumber(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

int* generateArry(int *length, int minValue, int valueLimit);

#endif