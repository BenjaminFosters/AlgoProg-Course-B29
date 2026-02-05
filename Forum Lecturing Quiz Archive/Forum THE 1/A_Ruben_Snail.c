#include <stdio.h>

int main(){
    int iteration, targetHeight, addedAltitude, descent, currentHeight, dayTrackr;
    scanf("%d", &iteration);
    
    for (int i = 0; i < iteration; i++) {
        currentHeight = 0;
        dayTrackr = 1;
        scanf("%d", &targetHeight);
        scanf("%d", &addedAltitude);
        scanf("%d", &descent);

        while (1 == 1) {
            if (currentHeight < 0) {
                printf("fail on day %d\n", dayTrackr);
                break;
            }

            currentHeight += addedAltitude - descent;

            if (currentHeight >= targetHeight) {
                printf("success on day %d\n", dayTrackr);
                break;
            }

            dayTrackr++;
        }
    }

    return 0;
}