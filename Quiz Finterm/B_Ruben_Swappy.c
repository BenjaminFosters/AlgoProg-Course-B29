#include <stdio.h>

int bubbleSortCountR(long int data[], int length) {
    int actionCounter = 0;
    for (int i = 0; i < length; i++) {
        for (int j = 1; j < length; j++) {
            if (data[j] < data[j-1]) {
                int temp = data[j];
                data[j] = data[j-1];
                data[j-1] = temp;
                actionCounter++;
            } 
        }
    }

    return actionCounter;
}

int main(){
    int iteration, length;
    long int numbers[1000];
    scanf("%d", &iteration);

    for (int i = 0; i < iteration; i++) {
        scanf("%d", &length);
        for (int j = 0; j < length; j++) {
            scanf("%ld", &numbers[j]);
        }

        printf("Case #%d: %d\n", i+1, bubbleSortCountR(numbers, length));
    }
    return 0;
}