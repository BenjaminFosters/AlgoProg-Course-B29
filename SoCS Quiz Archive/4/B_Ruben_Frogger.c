#include <stdio.h>

int main()
{
    int iterationRequired;
    long int frog[2];
    scanf("%d", &iterationRequired);

    for (int i = 0; i < iterationRequired; i++)
    {
        scanf("%ld %ld", &frog[0], &frog[1]);
        printf("Case #%d: %s\n", i + 1, ((frog[0] * frog[1]) % 2 == 0) ? "Party time!" : "Need more frogs");
    }
    return 0;
}