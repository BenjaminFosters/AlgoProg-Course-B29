#include <stdio.h>

int main(){
    int up, down, broken, output = 0;
    scanf("%d %d %d", &up, &down , &broken);
    if (up > broken || down < broken) {
        output = -1;
    } else {
        up = broken - up;
        down = down - broken;
        if (up == down) {
            output = down;
        } else {
            output = -1;
        }
    }

    printf("%d\n", output);

    return 0;
}