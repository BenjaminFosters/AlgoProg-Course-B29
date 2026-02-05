// Reversi! - Steve Ballmer (Windows 1.0 Ads)

#include <stdio.h>

int main(){
    char word[3][21];

    for (int i = 0; i < 3; i++) {
        scanf("%s", word[i]);
    }

    for (int i = 2; i >= 0; i--) {
        if (i == 0) {
            printf("%s\n", word[i]);
        } else{
            printf("%s ", word[i]);
        }
    }
    return 0;
}