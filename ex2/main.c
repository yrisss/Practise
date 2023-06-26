#include <stdio.h>

void compressArray(int A[], int n, int k) {
    int i, j;

    j = 0;
    for (i = 0; i < n; i++) {
        if (A[i] % k != 0) {
            A[j] = A[i];
            j++;
        }
    }

    for (i = j; i < n; i++) {
        A[i] = 0;
    }
}

int main() {
    int A[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int n = sizeof(A) / sizeof(A[0]); //число элементов в массиве
    int k = 3; //кратное
    int i;

    printf("Initial array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }

    compressArray(A, n, k);

    printf("\nCompressed array:: ");
    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }

    return 0;
}