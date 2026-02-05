#include <stdio.h>

void bubbleSort(int data[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (data[j] > data[j + 1])
            {
                int temp = data[j + 1];
                data[j + 1] = data[j];
                data[j] = temp;
            }
        }
    }
}

int main()
{
    int data[] = {80, 40, 20, 76, 11, 35};
    int size = sizeof(data) / sizeof(data[0]);
    bubbleSort(data, size);

    for (int i = 0; i < size - 1; i++)
    {
        printf("%d, ", data[i]);
    }
    return 0;
}