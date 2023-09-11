#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct University {
    int yearFounded;
    char name[50];
    char type[20];
};

int compareUniversities(const void *a, const void *b) {
    const struct University *uniA = (const struct University *)a;
    const struct University *uniB = (const struct University *)b;

    if (uniA->yearFounded > uniB->yearFounded) return -1;
    if (uniA->yearFounded < uniB->yearFounded) return 1;

    return strcmp(uniA->type, uniB->type);
}

void findOldestInstituteWithLetter(struct University *universities, int size, char letter) {
    struct University *oldestInstitute = NULL;

    for (int i = 0; i < size; i++) {
        if (strcmp(universities[i].type, "institute") == 0) {
            if (oldestInstitute == NULL || universities[i].yearFounded < oldestInstitute->yearFounded) {
                int len = strlen(universities[i].name);
                if (len > 0 && universities[i].name[len - 1] == letter) {
                    oldestInstitute = &universities[i];
                }
            }
        }
    }

    if (oldestInstitute != NULL) {
        printf("The oldest institute with a name ending in '%c':\n", letter);
        printf("Year of creation: %d\n", oldestInstitute->yearFounded);
        printf("Name: %s\n", oldestInstitute->name);
    } else {
        printf("Institute with select condition not found!\n");
    }
}

int main() {
    int size;
    printf("Enter number of educational establishments: ");
    scanf("%d", &size);

    struct University *universities = (struct University *)malloc(size * sizeof(struct University));

    if (universities == NULL) {
        printf("Memory allocation error.\n");
        return 1;
    }

    for (int i = 0; i < size; i++) {
        printf("Enter information about educational establishment %d:\n", i + 1);
        printf("Year of creation: ");
        scanf("%d", &universities[i].yearFounded);
        printf("Name: ");
        scanf("%s", universities[i].name);
        printf("Type (university, academy, institute): ");
        scanf("%s", universities[i].type);
    }

    qsort(universities, size, sizeof(struct University), compareUniversities);

    printf("\nEducational establishments after sorting by year of creation and type:\n");
    for (int i = 0; i < size; i++) {
        printf("Year of creation: %d, Name: %s, Type: %s\n",
               universities[i].yearFounded, universities[i].name, universities[i].type);
    }

    char letter;
    printf("\nEnter a letter to search for the oldest institute: ");
    scanf(" %c", &letter);

    findOldestInstituteWithLetter(universities, size, letter);

    free(universities);

    return 0;
}