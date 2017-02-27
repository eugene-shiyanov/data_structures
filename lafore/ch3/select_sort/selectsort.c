#include "array_sel.h"

int main() {
    int max_size = 100;
    ArraySel * arraySel = array_sel_new(max_size);
    array_sel_add(arraySel, 77);
    array_sel_add(arraySel, 99);
    array_sel_add(arraySel, 44);
    array_sel_add(arraySel, 55);
    array_sel_add(arraySel, 22);
    array_sel_add(arraySel, 88);
    array_sel_add(arraySel, 11);
    array_sel_add(arraySel, 00);
    array_sel_add(arraySel, 66);
    array_sel_add(arraySel, 33);

    array_sel_display(arraySel);
    array_sel_selectionSort(arraySel);
    array_sel_display(arraySel);
    array_sel_free(arraySel);
}
