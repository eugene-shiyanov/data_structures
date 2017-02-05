#include <string.h>
#include <stdio.h>
#include "vector.h"

const int INIT_SIZE = 10;
static bool expand_array_if_needed(Vector * vector);
static void * copy_element(const void * element, size_t el_size);

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
    if (!expand_array_if_needed(vector))
        return false;

    void * element_copy = copy_element(element, vector->el_size);

    if (!element_copy)
        return false;

    vector->array[vector->elems_count++] = element_copy;
    return true;
}

bool vector_insert(Vector * vector, const void * element, int index) {
    if (index < 0 || index > vector->elems_count)
        return false;

    if (!expand_array_if_needed(vector))
        return false;

    void * element_copy = copy_element(element, vector->el_size);

    if (!element_copy)
        return false;

    for (int i = vector->elems_count; i > index; i--)
        vector->array[i] = vector->array[i - 1];

    vector->array[index] = element_copy;
    vector->elems_count++;
    return true;
}

void * vector_get(const Vector * vector, int index) {
    if (index < 0 || index >= vector->elems_count)
        return NULL;

    return vector->array[index];
}

void * vector_remove(Vector * vector, int index) {
    if (index < 0 || index >= vector->elems_count)
        return NULL;

    void * element = vector->array[index];

    for (int i = index; i < (vector->elems_count -1); i++)
        vector->array[i] = vector->array[i + 1];

    vector->elems_count--;
    return element;
}

void vector_set_print_element_function(Vector * vector, void (*print_element) (void *)) {
    vector->print_element = print_element;
}

void vector_print(const Vector * vector) {
    printf("Vector: [");

    for (int i = 0; i < vector->elems_count; i++) {
        if (i != 0)
            printf(", ");

        vector->print_element(vector_get(vector, i));        
    }
    
    puts("]");
}

static bool expand_array_if_needed(Vector * vector) {
    if (vector->elems_count == vector->size) {
        void ** new_array = (void **) realloc(vector->array, sizeof(void *) * vector->size * 2);

        if (!new_array)
            return false;

        vector->array = new_array;
        vector->size *= 2;
    }

    return true;
}

static void * copy_element(const void * element, size_t el_size) {
    void * element_copy = malloc(el_size);

    if (!element_copy)
        return NULL;

    memcpy(element_copy, element, el_size);
    return element_copy;
}
