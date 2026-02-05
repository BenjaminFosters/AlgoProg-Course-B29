#include <stdio.h>

int main()
{
    int iteration;
    float price, discount, max;
    scanf("%d", &iteration);
    for (int i = 0; i < iteration; i++)
    {
        scanf("%f %f %f", &price, &discount, &max);
        discount /= 100.00;
        price *= discount;
        printf("Case #%d: %.0f\n", i+1, price > max ? max : price);
    }
    return 0;
}