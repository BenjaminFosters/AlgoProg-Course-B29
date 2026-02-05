#include <stdio.h>

void selectionSort(int arrayNumber[])
{
    int arrayNeeded = 3;
    for (int i = 0; i < arrayNeeded - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < arrayNeeded; j++)
        {
            if (arrayNumber[j] < arrayNumber[min])
                min = j;
        }
        int buff = arrayNumber[min];
        arrayNumber[min] = arrayNumber[i];
        arrayNumber[i] = buff;
    }
}

int main()
{

    return 0;
}