#include <stdio.h>

int main()
{
    int attempt;
    scanf("%d", &attempt);
    for (int i = 0; i < attempt; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}