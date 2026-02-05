#include <stdio.h>

int main()
{
    float sales;
    do
    {
        printf("Enter sales in dollars (-1 to end): ");
        scanf("%f", &sales);
        if (sales < 0)
        {
            break;
        }
        printf("Salary is: $%.2f\n\n", 200.00 + (sales * 0.09));
    } while (1);
    return 0;
}