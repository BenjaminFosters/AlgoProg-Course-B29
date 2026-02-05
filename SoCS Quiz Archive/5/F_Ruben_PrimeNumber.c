#include <stdio.h>

int main()
{
    int iteration, interlock;
    long long number;
    scanf("%d", &iteration);

    for (int i = 1; i <= iteration; i++)
    {
        interlock = 0;
        scanf("%lld", &number);
        for (int j = 1; j <= number + 1; j++)
        {
            if (j == number + 1)
            {
                interlock++;
            }
            else if (number % j == 0 && j != 1 && j != number)
            {
                break;
            }
        }
        printf("Case #%d: %s\n", i, interlock == 1 ? "prime" : "not prime");
    }
    return 0;
}