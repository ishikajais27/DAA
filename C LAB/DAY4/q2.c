//WAP to find max and min element in an array of thousand elements
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gen(int a[], int n) {
    for (int i = 0; i < n; i++)
        a[i] = rand() % 10000;
}

void maxmin(int a[], int n, int *mx, int *mn) {
    *mx = a[0];
    *mn = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > *mx) *mx = a[i];
        if (a[i] < *mn) *mn = a[i];
    }
}

int main() {
    int a[10000], n, x, y;
    srand(time(0));
    printf("Enter how many numbers (min 10, max 10000): ");
    scanf("%d", &n);
    if (n < 10 || n > 10000) {
        printf("Invalid size\n");
        return 0;
    }
    gen(a, n);
    

    printf("\nGenerated numbers:\n");
    for (int i = 0; i < n; i++) {
        printf("Line %d: %d\n", i + 1, a[i]);
    }

    maxmin(a, n, &x, &y);
    printf("\nmax=%d\nmin=%d\n", x, y);
    return 0;
}
