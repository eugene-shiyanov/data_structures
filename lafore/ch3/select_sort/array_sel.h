typedef struct array_sel {
    long * array;
    int size;
    int elems;
} ArraySel;

ArraySel * array_sel_new(int size);
void array_sel_free(ArraySel * arraySel);
void array_sel_add(ArraySel * arraySel, long value);
void array_sel_display(ArraySel * arraySel);
void array_sel_selectionSort(ArraySel * arraySel);
