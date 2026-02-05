#include <stdio.h>

int main()
{
    int iterate, dayExplore, animalsBrought, totalAnimals;
    scanf("%d", &iterate);
    for (int i = 0; i < iterate; i++) {
        totalAnimals = 0;
        scanf("%d", &dayExplore);
        for (int i = 0; i < dayExplore; i++) {
            scanf("%d", &animalsBrought);
            totalAnimals += animalsBrought;
        }
        printf("Case #%d: %d\n", i+1, totalAnimals);
    }

    return 0;
}