#include <stdio.h>

int main()
{
    long int numbers[4];

    for (int i = 0; i < 4; i++)
    {
        scanf("%ld", &numbers[i]);
    }

    numbers[0] = numbers[0] * numbers[1];
    numbers[2] = numbers[2] + numbers[3];

    printf("%s\n", numbers[0] > numbers[2] ? "True" : "False");
    return 0;
}