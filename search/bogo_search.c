#include "../include/bogo_search.h"
#include <time.h>
#include <stdlib.h>

// This is horrible 😂😂, y I am doing this... 4 real lol

int bogo_search(int *v, int len, int value_to_find, int max_attempts)
{
    srand(time(NULL));
    if (max_attempts <= 0)
        max_attempts = 15 * len;
    int count = 0;
    while (count < max_attempts)
    {
        int rand_idx = rand() % len;
        if (v[rand_idx] == value_to_find)
        {
            return rand_idx;
        }
        count++;
    }
    return -1;
}

// #include "include/bogo_search.h"

// int main(){
//     int *v = (int*) calloc(15, 15*sizeof(int));
//     for (int i = 0; i < 15; i++) {
//         v[i] = i;
//     }

//     printf("%d\n", bogo_search(v, 15, 6, 100000));
//     return 0;
// }

// #include "include/linkedQueue.h"
