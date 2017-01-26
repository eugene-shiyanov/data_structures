#include "array_bub.h"

const int MAX_SIZE = 100;

int main(void) {
    ArrayBub * arr = array_bub_new(MAX_SIZE);

    array_bub_insert(arr, 77);
    array_bub_insert(arr, 99);
    array_bub_insert(arr, 44);
    array_bub_insert(arr, 55);
    array_bub_insert(arr, 22);
    array_bub_insert(arr, 88);
    array_bub_insert(arr, 11);
    array_bub_insert(arr, 00);
    array_bub_insert(arr, 66);
    array_bub_insert(arr, 33);

    array_bub_display(arr);
    array_bub_bubble_sort(arr);
    array_bub_display(arr);
}
