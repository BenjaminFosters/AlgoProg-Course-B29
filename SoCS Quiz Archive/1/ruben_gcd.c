#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int inputBerapaKali;
    int inputBerapaArray;
    int angkaBuffer;
    int a;
    int b;


    // printf("Butuh Berapa Kali Case nya?\n> ");
    scanf("%d", &inputBerapaKali);

    if (inputBerapaKali > 100 || inputBerapaKali < 1) {
        // printf("Sorry nih, Case nya cuma boleh 1-100, tidak lebih, tidak kurang.\n");
        return 0;
    }

    int *jawabanCase = malloc(inputBerapaKali * sizeof(int));
    
    for (int i = 0; i < inputBerapaKali; i++) {
        // Ini input Berapa banyak Array
        // printf("Butuh Berapa Banyak Array nya?\n> ");
        scanf("%d", &inputBerapaArray);
        
        if (inputBerapaArray > 100 || inputBerapaArray < 2) {
            // printf("Here's the thing. Minimal Array nya cuma boleh ada 2, maksimal 100. Jadi mohon dikurangi.\n");
            return 0;
        }
        
        /* Malloc (Mem Allocation) Dynamic Array (Ref https://www.geeksforgeeks.org/c/dynamic-array-in-c/)
        Catatan, Include Standard Library ya!
        *arrayAngka itu bertujuan untuk bikin Array Secara Dynamic*/
        
        int *arrayAngka = malloc(inputBerapaArray * sizeof(int));
        
        // Input dan Cek Limit Semuanya. (Oh iya Math Lib harus pakai buat Pow, Exponen)
        // printf("Masukkin angkanya dulu bro\n> ");
        for (int j = 0; j < inputBerapaArray; j++) {
            scanf("%d", &arrayAngka[j]);

            if (arrayAngka[j] < 1 || arrayAngka[j] > pow(10, 9)) {
                // printf("Lho, ini kebanyakan angkanya (atau kedikitan), antara 1 sampai 10^{9} ya gaes.\n");
                return 0;
            }
        }

        // Sekarang Hitung Rumusnya (Aku ada bikin PoC di Python hence gampangan Portnya ke C)
        a = arrayAngka[0];
        for (int j = 1; j < inputBerapaArray; j++) {
            b = arrayAngka[j];
            while (b != 0) {
                angkaBuffer = b;
                b = a % b;
                a = angkaBuffer;
            }
        }
        jawabanCase[i] = a;
        free(arrayAngka);
    }

    // Presentasi Data
    for (int i = 0; i < inputBerapaKali; i++) {
        printf("Case #%d: %d\n", i+1, jawabanCase[i]);
    }

    free(jawabanCase);

    return 0;
}