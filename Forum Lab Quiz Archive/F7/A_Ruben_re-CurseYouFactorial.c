#include <stdio.h>

int main(){
    int fact, resFact;
    scanf("%d", &fact);

    resFact = fact;
    fact -= 1;

    for (; fact > 0; fact--) {
        resFact *= fact;
    }

    printf("%d\n", resFact);

    return 0;
}