#include <stdio.h>

int main(){
    int iteration, input;
    scanf("%d", &iteration);

    for (int i = 1; i <= iteration; i++) {
        scanf("%d", &input);
        printf("Case #%d:\n", i);
        for (int j = 1; j <= input; j++) {
            printf("%d %s\n", j, (j % 3 == 0 || j % 5 == 0) && j % 15 != 0 ? "Jojo" : "Lili");
        }
    }
    return 0;
}