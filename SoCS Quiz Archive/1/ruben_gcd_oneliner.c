#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {int c;int d;int e;int a;int b;scanf("%d", &c);if (c > 100 || c < 1) {return 0;}int *f = malloc(c * sizeof(int));for (int i = 0; i < c; i++) {scanf("%d", &d);if (d > 100 || d < 2) {return 0;}int *g = malloc(d * sizeof(int));for (int j = 0; j < d; j++) {scanf("%d", &g[j]);if (g[j] < 1 || g[j] > pow(10, 9)) {return 0;}}a = g[0];for (int j = 1; j < d; j++) {b = g[j];while (b != 0) {e = b;b = a % b;a = e;}}f[i] = a;free(g);}for (int i = 0; i < c; i++) {printf("Case #%d: %d\n", i+1, f[i]);}free(f);return 0;}