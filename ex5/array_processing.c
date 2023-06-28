#include <stdio.h>
#include <stdlib.h>

void compressArray(int *array, int size, int k) {
    int newSize = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] % k != 0) {
            array[newSize++] = array[i];
        }
    }

    for (int i = newSize; i < size; i++) {
        array[i] = 0;
    }
}