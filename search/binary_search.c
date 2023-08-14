#include "../include/binary_search.h"
#include <stdio.h>

int binary_search(int *numbers, int length, int number)
{
    int left = 0;
    int right = length - 1;
    while (right > left)
    {
        int middle = (left + right) / 2;
        if (numbers[middle] == number)
        {
            return middle;
        }
        else if (number > middle)
        {
            left = middle;
        }
        else
        {
            right = middle;
        }
    }
    return -1;
}
