#include <stdio.h>

int main(){
    int a, b, c, largest;
    scanf("%d %d %d", &a, &b, &c);

    largest = b;
    if (a > b) {
        largest = a;
        if (largest < c) {
            largest = c;
        }
    }

    printf("%d\n", largest);
    return 0;
}