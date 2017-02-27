#include <stdio.h>
#include <stdlib.h>
#include "array_sel.h"

static void swap(long * array, int one, int two);

ArraySel * array_sel_new(int size) {
    ArraySel * arraySel = malloc(sizeof(ArraySel));
    arraySel->array = malloc(sizeof(long) * size);
    arraySel->size = size;
    arraySel->elems = 0;
    return arraySel;
}

void array_sel_free(ArraySel * arraySel) {
    free(arraySel->array);
    free(arraySel);
}

void array_sel_add(ArraySel * arraySel, long value) {
    arraySel->array[arraySel->elems] = value;
    arraySel->elems++;
}

void array_sel_display(ArraySel * arraySel) {
    for (int i = 0; i < arraySel->elems; i++)
        printf("%d ", arraySel->array[i]);
    puts("");
}

void array_sel_selectionSort(ArraySel * arraySel) {
    long * array = arraySel->array;

    for (int out = 0; out < arraySel->elems - 1; out++) {
        int min = out;

        for (int in = out + 1; in < arraySel->elems; in++)
            if (array[in] < array[min])
                min = in;

        swap(array, out, min); 
    }
}

static void swap(long * array, int one, int two) {
    long temp = array[one];
    array[one] = array[two];
    array[two] = temp;
}
