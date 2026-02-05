#include <stdio.h>
#include <string.h>

void reverseText(char text[]) {
	int len = strlen(text);
	char wordNew[len+1];
	
	for (int i = 0; i < len; i++) {
        wordNew[i] = text[len - 1 - i];
    }

	// Null Terminator (Recommendation from GPT5)
	wordNew[len] = '\0';
	strcpy(text, wordNew);
}

void reverseCase(char text[]) {
	int len = strlen(text);
	for (int i = 0; i < len-1; i++) {
		if (text[i] >= 'A' && text[i] <= 'Z') {
			text[i]+=32;
		} else if (text[i] >= 'a' && text[i] <= 'z') {
			text[i]-=32;
		}
	}
}

int main(){
	char word[101];
	
	printf("Declare yer word: ");
	scanf(" %[^\n]", word);
	
	reverseText(word);
	reverseCase(word);

	printf("%s\n", word);
}
