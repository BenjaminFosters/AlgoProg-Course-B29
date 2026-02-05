#include <stdio.h>

long long F(int n, int *cFX) {
    // printf("Before Case: %d\n", n);
    if (n == 0) {
        return 1;
    }
    if (n == 1) {
        return 2;
    }
    // printf("Near Checking: %d\n", n);
    if (n == 3 || n == 4) {
        // printf("Passed: %d\n", n);
        (*cFX)++;
        // printf("Passed: %d\n", cFX);
    }
    // printf("Post Check: %d\n", n);

    if (n % 3 == 0) {
        return F(n - n/3, cFX) + 1;
    } else {
        return F(n-1, cFX) + n + F(n-2, cFX) + 1;
    }
}

int main() {
    int iteration, chosenNumber, cFX, results;
    scanf("%d", &iteration);

    for (int currentIteration = 0; currentIteration < iteration; currentIteration++) {
        cFX = 0;
        scanf("%d", &chosenNumber);
        results = F(chosenNumber, &cFX);
        printf("Case #%d: %lld %d\n", currentIteration+1, results, cFX);
    }

    return 0;
}