#include <stdio.h>

void compressArray(int *A, int n, int k) {
    int *p = A; // Указатель на текущий элемент массива
    int *end = A + n; // Указатель на конец массива

    while (p < end) {
        if (*p % k == 0) {
            // Элемент кратный k, удаляем его путем сдвига всех последующих элементов
            int *q = p;
            while (q < end - 1) {
                *q = *(q + 1);
                q++;
            }

            // Заполняем последний элемент нулем
            *(end - 1) = 0;

            // Уменьшаем размер массива
            end--;
        } else {
            // Элемент не кратный k, переходим к следующему элементу
            p++;
        }
    }
}

int main() {
    int A[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int n = sizeof(A) / sizeof(A[0]); //Количество элементов массива
    int k = 3; //Кратное
    int i;

    printf("Initial array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }

    compressArray(A, n, k);

    printf("\nCompressed array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }

    return 0;
}