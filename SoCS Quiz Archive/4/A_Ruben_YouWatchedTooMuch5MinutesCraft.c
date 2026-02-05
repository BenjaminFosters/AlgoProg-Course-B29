#include <stdio.h>

int main()
{
    int iterationRequired, neededRamen, ramenAtHome, ramenAtStore;

    scanf("%d", &iterationRequired);
    for (int i = 0; i < iterationRequired; i++)
    {
        scanf("%d %d %d", &neededRamen, &ramenAtHome, &ramenAtStore);

        printf("Case #%d: %s\n", i + 1, (neededRamen > (ramenAtHome + ramenAtStore)) ? "no" : "yes");
    }
    return 0;
}