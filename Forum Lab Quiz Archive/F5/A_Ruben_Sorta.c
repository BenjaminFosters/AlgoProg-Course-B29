#include <stdio.h>

int main()
{
    int numbersOfDreams[5], largestNumber;
    printf("Input 5 Numbers\n");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &numbersOfDreams[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        if (i == 0 || largestNumber < numbersOfDreams[i])
        {
            largestNumber = numbersOfDreams[i];
        }
    }

    printf("%d", largestNumber);
    return 0;
}