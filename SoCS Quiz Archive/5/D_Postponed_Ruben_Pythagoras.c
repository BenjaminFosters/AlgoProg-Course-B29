#include <stdio.h>
#include <math.h>

int main(){
    int iteration, a, b, c, x, y, z;
    scanf("%d", &iteration);

    for (int i = 0; i < iteration; i++) {
        scanf("%d %d %d", &a, &b, &c);

        //Sort dari kode SoCS kemarin
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

        printf("Case #%d: %s\n", i+1, sqrt(pow(a, 2) + pow(b, 2)) == c ? "Yes": "No");
    }
    return 0;
}
