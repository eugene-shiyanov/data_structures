#ifndef VECTOR_H
#define VECTOR_H
#include <stdlib.h>
#include <stdbool.h>

typedef struct vector {
    void ** array;
    int elems_count;
    int size;
    size_t el_size;
    void (*print_element) (void *);
} Vector;

Vector * vector_new(size_t el_size);
void vector_destroy(Vector * vector);
bool vector_add(Vector * vector, const void * element);
bool vector_insert(Vector * vector, const void * element, int index);
void * vector_get(const Vector * vector, int index);
void * vector_remove(Vector * vector, int index);
void vector_set_print_element_function(Vector * vector, void (*print_element) (void *));
void vector_print(const Vector * vector);

#endif
