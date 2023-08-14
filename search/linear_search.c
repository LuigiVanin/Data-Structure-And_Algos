#include "../include/linear_search.h"

int linear_search(int *v, int len, int value_to_find)
{
    for (int i = 0; i < len; i++)
    {
        if (v[i] == value_to_find)
        {
            return i;
        }
    }
    return -1;
}