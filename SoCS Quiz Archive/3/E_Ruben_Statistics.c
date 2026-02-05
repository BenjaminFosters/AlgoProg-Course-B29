#include <stdio.h>

// Ditujukan untuk Debugging Logic
// int callText(int arrayNeeded, int arrayNumber[]){
//     for (int k = 0; k < arrayNeeded; k++) {
//         printf("%d - ", arrayNumber[k]);
//     }
//     printf("\n");

//     return 0;
// }

void selectionSort(int arrayNeeded, int arrayNumber[]) {
    for (int i = 0; i < arrayNeeded - 1; i++) {
        int min = i;
        for (int j = i + 1; j < arrayNeeded; j++) {
            if (arrayNumber[j] < arrayNumber[min])
                min = j;
        }
        int buff = arrayNumber[min];
        arrayNumber[min] = arrayNumber[i];
        arrayNumber[i] = buff;
    }
}

int main() {
    int iteration, arrayNeeded, arrayNumber[5000];
    
    // Melihat Suggestion dari ChatGPT, bahwa ada kemungkinan Integer berukuran besar 16^10 * 5000
    long long int calculateTotal;

    scanf("%d", &iteration);

    for (int iterate = 0; iterate < iteration; iterate++) {
        scanf("%d", &arrayNeeded);

        calculateTotal = 0;

        for (int alsoIterate = 0; alsoIterate < arrayNeeded; alsoIterate++) {
            scanf("%d", &arrayNumber[alsoIterate]);
            calculateTotal += arrayNumber[alsoIterate];
        }

        // Selection Sort (BINUS Session 11 LAB)
        selectionSort(arrayNeeded, arrayNumber);
        
        // Double karena lagi-lagi, Large Data
        printf("Case #%d:\nMean : %.2f\nMedian : %.2f\n", iterate+1, (double)calculateTotal / (double)arrayNeeded, ((arrayNeeded % 2) == 1) ? (double)arrayNumber[((arrayNeeded-1)/2)] : ((double)arrayNumber[((arrayNeeded-1)/2)] + (double)arrayNumber[((arrayNeeded-1)/2)+1])/2.00);
    }

    return 0;
}