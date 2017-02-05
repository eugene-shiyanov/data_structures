#include <stdio.h>
#include "vector.h"

int main(void) {
    Vector * vector = vector_new(sizeof(int));

    for (int i = 0; i < 30; i++) {
        vector_add(vector, &i);
    }

    for (int i = 0; i < vector->elems_count; i++) {
        int * element = (int *) vector_get(vector, i);
        printf("%d ", *element);
    }

    puts("\n insert:");
    int i = 99;
    vector_insert(vector, &i, 5);
    vector_insert(vector, &i, 0);
    vector_insert(vector, &i, vector->elems_count);

    for (int i = 0; i < vector->elems_count; i++) {
        int * element = (int *) vector_get(vector, i);
        printf("%d ", *element);
    }

    puts("\n remove:");
    int * ptr = vector_remove(vector, 5);
    free(ptr);
    ptr = vector_remove(vector, 5);

    for (int i = 0; i < vector->elems_count; i++) {
        int * element = (int *) vector_get(vector, i);
        printf("%d ", *element);
    }

    printf("\nlast removed: %d\n", *ptr);
    free(ptr);
    vector_destroy(vector);
    
    return 0;
}
