#include <stdio.h>

int main(){
    int iteration, paws;
    int rooms[100], currentRoom, counter = 0;

    scanf("%d", &iteration);

    for (int i = 0; i < iteration; i++) {
        scanf("%d", &paws);

        for (int j = 1; j < paws+1; j++) {
            currentRoom = 1;
            if (j > 1) {
                while (1) {
                    currentRoom *= j;
                    if (currentRoom < paws+1) {
                        rooms[currentRoom-1] = rooms[currentRoom-1] == 0 ? 1 : 0;
                    } else {
                        break;
                    }
                }
            }
            else {
                for (int k = 1; k < 100; k++) {
                    rooms[k] = 1;
                }
            }
        }

        for (int j = 0; j < paws; j++) {
            if (rooms[j] == 1) {
                counter++;
            }
        }

        printf("%d\n", counter);
    }
    return 0;
}