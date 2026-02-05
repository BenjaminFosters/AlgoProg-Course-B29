#include <stdio.h>
#include <math.h>

int main()
{
    int number = 0;
    scanf("%d", &number);
    printf("%d\n", (1 << number) - 1);
    return 0;
}