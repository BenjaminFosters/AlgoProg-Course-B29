#include <stdio.h>
#include <string.h>

int main(){
    char words[61];

    for (int i = 0; i < 2; i++) {
        scanf(" %[^\n]", words);
        for (int j = 0; j < strlen(words); j++) {
            printf("%c", words[j]);

            if (words[j+1] == ' ' || j == strlen(words)-1) {
                printf("%s", "szs");
            }
        }
        printf("\n");
    }

    return 0;
}