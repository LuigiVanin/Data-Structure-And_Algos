#define CPPALGOS_BOGOSORT_H
#ifdef CPPALGOS_BOGOSORT_H
#include <stdbool.h>

void bogo_sort(int *array, int size);
bool is_sorted(int *array, int size);
void shuffle(int *array, int size);

#endif