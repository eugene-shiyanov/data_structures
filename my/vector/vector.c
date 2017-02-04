#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "vector.h"

const int INIT_SIZE = 10;

Vector * vector_new(size_t el_size) {
    Vector * vector = (Vector *) malloc(sizeof(Vector));
    vector->array = (void **) malloc(sizeof(void *) * INIT_SIZE);
    vector->elems_count = 0;
    vector->size = INIT_SIZE;
    vector->el_size = el_size;
    return vector;
}

void vector_destroy(Vector * vector) {
    for (int i = 0; i < vector->elems_count; i++)
        free(vector->array[i]);

    free(vector->array);
    free(vector);
}

bool vector_add(Vector * vector, const void * element) {
    if (vector->elems_count == vector->size) {
        void ** new_array = (void **) realloc(vector->array, sizeof(void *) * vector->size * 2);

        if (!new_array) {
            return false;
        }

        vector->array = new_array;
        vector->size *= 2;
    }

    void * element_copy = malloc(vector->el_size);

    if (!element_copy) {
        return false;
    }

    memcpy(element_copy, element, vector->el_size);
    vector->array[vector->elems_count++] = element_copy;
    return true;
}

void * vector_get(const Vector * vector, int index) {
    return vector->array[index];
}



int main(void) {
    Vector * vector = vector_new(sizeof(int));

    for (int i = 0; i < 30; i++) {
        vector_add(vector, &i);
    }

    for (int i = 0; i < vector->elems_count; i++) {
        int * element = (int *) vector_get(vector, i);
        printf("%d ", *element);
    }

    puts("");
    vector_destroy(vector);
    
    return 0;
}
