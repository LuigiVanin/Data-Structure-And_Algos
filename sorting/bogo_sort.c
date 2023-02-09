#include "../include/bogo_sort.h"
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include "../include/utils.h"

void bogo_sort(int *array, int size) {
    while (!is_sorted(array, size)) {

        shuffle(array, size);
    }
}