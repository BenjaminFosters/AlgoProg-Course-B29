#include <stdio.h>

int main(){
    char word[5][11];

    for (int i = 0; i < 5; i++) {
        scanf("%s", word[i]);
    }

    for (int i = 0; i < 5; i++) {
        printf("%10s|%-s\n", word[i], word[i]);
    }

    return 0;
}