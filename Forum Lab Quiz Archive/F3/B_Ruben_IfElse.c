#include <stdio.h>

int main(){
    int a, b, c, largest;
    scanf("%d %d %d", &a, &b, &c);

    if (a > b) {
        largest = a;
    } else {
        largest = b;
    }

    if (b < c) {
        largest = c;
    }

    printf("%d\n", largest);
    return 0;
}