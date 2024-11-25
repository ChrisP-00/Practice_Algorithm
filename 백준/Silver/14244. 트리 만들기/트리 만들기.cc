#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n - m; ++i) {
        printf("%d %d\n", i, i + 1);
    }

    for (int i = n - m + 1; i < n; ++i) {
        printf("%d %d\n", n - m, i);
    }

    return 0;
}