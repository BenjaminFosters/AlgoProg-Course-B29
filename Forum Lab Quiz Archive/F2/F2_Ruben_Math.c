#include <stdio.h>

int main() {
    int a;
    int b;

    printf("Enter the first integer: ");
    scanf("%d", &a);
    printf("Enter the second integer: ");
    scanf("%d", &b);

    printf("Sum        : %d\n", a+b);
    printf("Product    : %d\n", a*b);
    printf("Difference : %d\n", a-b);
    printf("Quotient   : %f\n", (float)a/(float)b);
    printf("Remainer   : %d\n", a%b);
    return 0;
}