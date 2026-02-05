#include <stdio.h>
#include <string.h>

int main(){
    int iteration, longDigit, targetedChar;
    char whatCharDoYouNeed[100000] = ""; // Ini panjangnya agak abritary, tapi kalo Bapak Alvin sendiri berkenan untuk memberikan solusi yang lebih dinamis, dipersilahkan. Thank You!
    char buffer[1000];
    scanf("%d", &iteration);

    for (int i = 0; i < iteration; i++) {
        scanf("%d", &longDigit);
        scanf("%d", &targetedChar);

        longDigit++;
        for (int j = 0; j < longDigit; j++) {
            // Menurut ChatGPT (GPT-5, Online) dan GeeksForGeeks, salah satu cara mudahnya menggunakan library dimana Int di print dan diletakan di Buffer. Sebelum di Merge dengan whatCharDoYouNeed
            // (yes, kecuali di production, nama variabel saya suka aneh-aneh, jangan kaget Pak hehe.)
            sprintf(buffer, "%d", j % longDigit);
            strcat(whatCharDoYouNeed, buffer);
        }
        printf("%c\n", whatCharDoYouNeed[targetedChar]);
    }

    return 0;
}