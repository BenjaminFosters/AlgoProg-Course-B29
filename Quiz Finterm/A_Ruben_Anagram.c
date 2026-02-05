#include <stdio.h>
#include <string.h>

void sanitizeInput(char word[]) {
    // Mekanisme, Convert apapun yang < 65+32 ke Huruf Kecil di ASCII (+32)
    int length = strlen(word);
    char newWord[100001];
    for (int i = 0; i < length; i++) {
        if (word[i] != ' ') {
            sprintf(newWord, "%s%c", newWord,  i < 65+32 ? word[i-32] : word[i]);
        }
    }
    strcpy(word, newWord);
    strcpy(newWord, "");
}

int wordID(char word[]) {
    int length = strlen(word);
    int identify = 0;
    for (int i = 0; i < length; i++) {
        identify = identify + word[i];
    }
    return identify;
}

int compWord(char wordFormer[], char wordLatter[]) {
    int lengthFormer = strlen(wordFormer);
    int lengthLatter = strlen(wordLatter);
    
    if (lengthFormer == lengthLatter) {
        if (wordID(wordFormer) == wordID(wordLatter)) {
            return 0;
        };
    }

    return 1;
}

int main(){
    int iteration;
    char originalWord[100001], compToWord[100001];
    scanf("%d", &iteration);
    for (int i = 0; i < iteration; i++) {
        scanf(" %[^\n]", originalWord);
        scanf(" %[^\n]", compToWord);

        sanitizeInput(originalWord);
        sanitizeInput(compToWord);

        if (compWord(originalWord, compToWord)) {
            printf("Case %d: NO\n", i+1);
        } else {
            printf("Case %d: YES\n", i+1);
        }
    }
    return 0;
}