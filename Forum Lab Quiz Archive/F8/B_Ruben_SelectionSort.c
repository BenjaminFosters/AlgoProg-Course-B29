#include <stdio.h>

void selectionSort(int data[], int size) {
    int min;
    for (int i = 0; i < size-1; i++) {
        min = i;

        for (int j = i+1; j < size; j++) {
            if (data[j] < data[min]) {
                min = j;
            }
        }

        int temp = data[min];
        data[min] = data[i];
        data[i] = temp;
    }
}

int main(){
    int data[] = {80, 40, 20, 76, 11, 35};
    int size = sizeof(data) / sizeof(data[0]);
    selectionSort(data, size);

    for (int i = 0; i < size - 1; i++) {
        printf("%d, ", data[i]);
    }
    return 0;
}