#include <stdio.h>
#include "vector.h"

static void print_int(void *);

int main(void) {
    Vector * vector = vector_new(sizeof(int));
    vector_set_print_element_function(vector, print_int);

    for (int i = 0; i < 30; i++) {
        vector_add(vector, &i);
    }

    vector_print(vector);
    puts("insert:");
    int i = 99;
    vector_insert(vector, &i, 5);
    vector_insert(vector, &i, 0);
    vector_insert(vector, &i, vector->elems_count);
    vector_print(vector);
    puts("remove:");
    int * ptr = vector_remove(vector, 5);
    free(ptr);
    ptr = vector_remove(vector, 5);
    vector_print(vector);
    printf("last removed: %d\n", *ptr);
    free(ptr);
    vector_destroy(vector);
    return 0;
}

static void print_int(void * element) {
    printf("%d", *(int*)element);
}
