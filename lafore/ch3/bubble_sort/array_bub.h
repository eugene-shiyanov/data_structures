#ifndef ARRAY_BUB_H
#define ARRAY_BUB_H
#include <stdbool.h>

typedef struct array_bub {
    long * a;
    int size;
    int n_elems;
} ArrayBub;

ArrayBub * array_bub_new(int size);

bool array_bub_insert(ArrayBub * array_bub, long value);

void array_bub_display(const ArrayBub * array_bub);

void array_bub_bubble_sort(const ArrayBub * array_bub);

void array_bub_destroy(ArrayBub * array_bub);

#endif
