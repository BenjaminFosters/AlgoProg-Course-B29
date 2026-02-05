#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int choice, imSoRandom, storedFileCount = 0;
    char formatChoice[11], fileNameChoice[21], storedFiles[101][25], storedFilesSize[101][100];
    float fileSize;

    while (1) {
        printf("Hextech File History\n");
        printf("==========================\n");
        printf("1. Save a File\n");
        printf("2. History\n");
        printf("3. Remove All Files\n");
        printf("4. Exit\n");
        printf("Choice: ");

        scanf("%d", &choice);

        switch (choice) {

            // Case 1 DONE
            case 1: {
                printf("\nSave a File\n");

                while (1) {
                    printf("\nChoose Filetype [document|image]: ");
                    
                    // Input
                    scanf("%s", formatChoice);
                    if (!strcmp(formatChoice, "document") || !strcmp(formatChoice, "image")) {
                        break;
                    }
                }
                
                while (1) {
                    printf("\nInput Filename [5-20 Chars Long]: ");
                    
                    // FN
                    scanf(" %[^\n]", fileNameChoice);
                    if (strlen(fileNameChoice) <= 20 && strlen(fileNameChoice) >= 5 ) {
                        break;
                    }
                }

                while (1) {
                    imSoRandom = rand()/1000000;
                    if (imSoRandom/100 < 10) {
                        fileSize = (float)imSoRandom / (float)100;
                        break;
                    }
                }
                sprintf(storedFiles[storedFileCount], "%s.%s", fileNameChoice, !strcmp(formatChoice, "document") ? "doc" : "jpg");
                sprintf(storedFilesSize[storedFileCount], "%.2f", fileSize);
                
                printf("You saved %s (%s MB)\n", storedFiles[storedFileCount], storedFilesSize[storedFileCount]);
                storedFileCount++;
                
                printf("\nPress Enter to continue...");
                printf("\n\n");
                
                break;
            }
            // =====
            
            // Case 2
            case 2: {
                printf("\nHistory\n\n");
                
                for (int i = 0; i < storedFileCount; i++) {
                    printf("File Number %03d : %24s (%s MB)\n", i+1, storedFiles[i], storedFilesSize[i]);
                }
                
                printf("\nPress Enter to continue...");
                printf("\n\n");
                break;
            }
            // ====
            
            // Case 3
            case 3: {
                printf("\nRemove All Files\n\n");
                
                
                for (int i = 0; i < storedFileCount; i++) {
                    sprintf(storedFiles[storedFileCount], "");
                    sprintf(storedFilesSize[storedFileCount], "");
                }

                storedFileCount = 0;

                printf("All Files Are Removed!\n");
                
                printf("\nPress Enter to continue...");
                printf("\n\n");
                break;
            }
            
            case 4: {
                return 0;
            }
        }
    }
}