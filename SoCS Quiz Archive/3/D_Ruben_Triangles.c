#include <stdio.h>

int main() {
    int iteration, a, b, c, x, y, z;
    
    scanf("%d", &iteration);

    for (int i = 0; i < iteration; i++) {
        scanf("%d %d %d", &a, &b, &c);

        if (a >= b) {
            x = b;
            if (a >= c) {
                y = c;
                z = a;
            } else {
                y = a;
                z = c;
            }
        } else {
            x = a;
            if (b >= c) {
                y = c;
                z = b;
            } else {
                y = b;
                z = c;
            }
        }

        c = z;

        if (x >= y) {
            a = y;
            b = x;
        } else {
            a = x;
            b = y;
        }
    
        if ((a + b) > c) {
            printf("BISA\n");
        } else {
            printf("TIDAK BISA\n");
        }
    }
    return 0;
}