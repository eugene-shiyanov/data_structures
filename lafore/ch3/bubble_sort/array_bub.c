#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "array_bub.h"

ArrayBub * array_bub_new(int size) {
    ArrayBub * array_bub = malloc(sizeof(ArrayBub));
    array_bub->a = malloc(sizeof(long) * size);
    array_bub->size = size;
    array_bub->n_elems = 0;
    return array_bub;
}

bool array_bub_insert(ArrayBub * array_bub, long value) {
    if (array_bub->n_elems < array_bub->size) {
        array_bub->a[array_bub->n_elems] = value;
        array_bub->n_elems++;
        return true;
    } else 
        return false;
}

void array_bub_display(const ArrayBub * array_bub) {
    for (int i = 0; i < array_bub->n_elems; i++)
        printf("%d ", array_bub->a[i]);
    puts("\n");
}

void array_bub_destroy(ArrayBub * array_bub) {
    free(array_bub->a);
    free(array_bub);
    array_bub = NULL;
}
