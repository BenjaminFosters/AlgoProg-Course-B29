#include <stdio.h>
#include <string.h>

int main(){
    char title[5][101], author[5][101], bookCode[5][101];
    int publishedYear[5];

    printf("%15sWelcome to Blues Library\n", " ");
    printf("%15s========================\n\n", " ");

    for (int i = 0; i < 4; i++) {
        printf("Insert Book Title: ");
        scanf(" %[^\n]", title[i]);
        printf("Insert Book Author: ");
        scanf(" %[^\n]", author[i]);
        printf("Insert Book Published Year: ");
        scanf(" %d", &publishedYear[i]);
        printf("\n");
    }
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < strlen(title[i]); j++) {
            if (j == 0) {
                sprintf(bookCode[i], "%c", title[i][j]);
            } else {
                if (title[i][j-1] == ' ')
                sprintf(bookCode[i], "%s%c", bookCode[i], title[i][j]);
            }
        }
        printf("\n");
    }

    printf("\n\nProcessing...\n\nYour Collections :\n");

    for (int i = 0; i < 4; i++) {
        printf("%d. Shelf Code : %s\n", i+1, bookCode[i]);
        printf("   Book Code   : %c%c%d\n", title[i][0], author[i][0], publishedYear[i]);
        printf("   Title       : %s\n", title[i]);
        printf("   Author      : %s\n", author[i]);
        printf("   Publish Year: %d\n", publishedYear[i]);

        printf("\n\n");
    }
    return 0;
}