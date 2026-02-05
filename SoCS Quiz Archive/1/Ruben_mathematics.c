#include <stdio.h>

int main() {
    int a;
    int b;

    scanf("%d", &a);
    if (a > 1000 || a < 0) {
        return 0;
    }
    
    scanf("%d", &b);
    if (b > 1000 || b < 0) {
        return 0;
    }
    
    int add;
    add = a + b;

    printf("%d\n", add);
    return 0;
}