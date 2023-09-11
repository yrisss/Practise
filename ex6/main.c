#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Структура для описания ВУЗа
struct University {
    int yearFounded;
    char name[50];
    char type[20];
};

// Функция для сравнения ВУЗов при сортировке
int compareUniversities(const void *a, const void *b) {
    const struct University *uniA = (const struct University *)a;
    const struct University *uniB = (const struct University *)b;

    // Сортируем по убыванию года создания
    if (uniA->yearFounded > uniB->yearFounded) return -1;
    if (uniA->yearFounded < uniB->yearFounded) return 1;

    // Если годы создания одинаковые, сортируем по типу
    return strcmp(uniA->type, uniB->type);
}

// Функция для поиска самого старого института с заданной буквой в конце названия
void findOldestInstituteWithLetter(struct University *universities, int size, char letter) {
    struct University *oldestInstitute = NULL;

    for (int i = 0; i < size; i++) {
        if (strcmp(universities[i].type, "институт") == 0) {
            if (oldestInstitute == NULL || universities[i].yearFounded < oldestInstitute->yearFounded) {
                // Проверяем, заканчивается ли название на заданную букву
                int len = strlen(universities[i].name);
                if (len > 0 && universities[i].name[len - 1] == letter) {
                    oldestInstitute = &universities[i];
                }
            }
        }
    }

    if (oldestInstitute != NULL) {
        printf("Самый старый институт с названием, заканчивающимся на '%c':\n", letter);
        printf("Год создания: %d\n", oldestInstitute->yearFounded);
        printf("Название: %s\n", oldestInstitute->name);
    } else {
        printf("Институт с заданным условием не найден.\n");
    }
}

int main() {
    int size;
    printf("Введите количество ВУЗов: ");
    scanf("%d", &size);

    // Выделяем память под динамический массив структурных переменных
    struct University *universities = (struct University *)malloc(size * sizeof(struct University));

    if (universities == NULL) {
        printf("Ошибка выделения памяти.\n");
        return 1;
    }

    // Заполняем массив с клавиатуры
    for (int i = 0; i < size; i++) {
        printf("Введите информацию о ВУЗе #%d:\n", i + 1);
        printf("Год создания: ");
        scanf("%d", &universities[i].yearFounded);
        printf("Название: ");
        scanf("%s", universities[i].name);
        printf("Тип (университет, академия, институт): ");
        scanf("%s", universities[i].type);
    }

    // Сортируем ВУЗы по убыванию года создания
    qsort(universities, size, sizeof(struct University), compareUniversities);

    printf("\nВУЗы после сортировки по году создания и типу:\n");
    for (int i = 0; i < size; i++) {
        printf("Год создания: %d, Название: %s, Тип: %s\n",
               universities[i].yearFounded, universities[i].name, universities[i].type);
    }

    char letter;
    printf("\nВведите букву для поиска самого старого института: ");
    scanf(" %c", &letter);

    findOldestInstituteWithLetter(universities, size, letter);

    // Освобождаем выделенную память
    free(universities);

    return 0;
}
