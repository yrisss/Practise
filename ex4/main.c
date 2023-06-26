#include <stdio.h>
#include <string.h>

void reverseAppend(char *word) {
    int length = strlen(word);

    // Дописываем символы в обратном порядке
    for (int i = length - 1; i >= 0; i--) {
        word[length] = word[i];
        length++;
    }

    // Завершаем строку нулевым символом
    word[length] = '\0';
}

int main() {
    char word[100];

    printf("Enter the word: ");
    scanf("%s", word);

    reverseAppend(word);

    printf("Result: %s\n", word);

    return 0;
}