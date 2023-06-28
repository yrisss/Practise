#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compressArray(int *array, int size, int k);

int main() {
    char *inputFileName = "input.in";
    char *outputFileName = "input.out";

    FILE *inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        printf("Failed to open file %s.\n", inputFileName);
        return 1;
    }

    int n, k;
    if (fscanf(inputFile, "%d %d", &n, &k) != 2) {
        printf("Error reading array size and k value from file.\n");
        fclose(inputFile);
        return 1;
    }

    int *array = (int *)malloc(n * sizeof(int));
    if (array == NULL) {
        printf("Array memory allocation error.\n");
        fclose(inputFile);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        if (fscanf(inputFile, "%d", &array[i]) != 1) {
            printf("Error reading array elements from file.\n");
            free(array);
            fclose(inputFile);
            return 1;
        }
    }

    fclose(inputFile);

    compressArray(array, n, k);

    FILE *outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        printf("Failed to create file %s.\n", outputFileName);
        free(array);
        return 1;
    }

    fprintf(outputFile, "%d %d\n", n, k);
    for (int i = 0; i < n; i++) {
        fprintf(outputFile, "%d ", array[i]);
    }

    fclose(outputFile);
    free(array);

    printf("Array processing completed successfully. The result is written to a file %s.\n", outputFileName);

    return 0;
}