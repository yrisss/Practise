#include <stdio.h>

int main() {

    int firstNumber, number = 0, count = 0;


    printf("Enter a sequence of numbers (input ending - negative number):\n");
    scanf("%d ", &firstNumber);

    while(number >= 0)
    {
        scanf("%d", &number);
        printf(" ");
        if (number % firstNumber == 0)
            count++;

    }


    printf("\nNumber of sequence numbers, that are divisible by first number of sequence (%d): %d\n", firstNumber, count);

    return 0;
}