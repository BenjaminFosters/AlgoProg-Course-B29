#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int arrayNeeded, maxNum;

    scanf("%lld", &arrayNeeded);
    long long int *arrayNumbers = malloc(arrayNeeded * sizeof(long long int));

    for (long long int j = 0; j < arrayNeeded; j++)
    {
        scanf("%lld", &arrayNumbers[j]);
    }

    scanf("%lld", &maxNum);

    long long int maxValue = 0;
    int skipInterlock = 0;

    for (int k = 0; k < arrayNeeded; k++)
    {
        if (skipInterlock == 1)
        {
            break;
        }
        for (int x = 1; x <= arrayNeeded - k; x++)
        {
            long long fxk = 0;
            for (long long int iteration2 = 0; iteration2 < k; iteration2++)
            {
                fxk += arrayNumbers[x + iteration2] * (k - iteration2);
                if (fxk > maxNum)
                {
                    skipInterlock = 1;
                }
                else
                {
                    if (fxk > maxValue)
                    {
                        maxValue = fxk;
                    }
                }
            }
        }
    }

    printf("%lld\n", maxValue);
    return 0;
}

/*
f(x,k) = A[x] * k+A[x+1] * (k - 1)+ ... +A[x+k 1] * 1
Test Case 1

N    = 5
A[i] = 6 1 3 4 6
M    = 10

Selama f(x,k) >= M
k bisa memiliki value berapa pun selama <= N

Rumusnya itu contohnya f(3,2) = 3 x 2 + 4 x 1 = 10 (Highest Val)
*/