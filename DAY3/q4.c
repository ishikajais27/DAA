//Write a recursive program for binary search
#include <stdio.h>
int bs(int a[], int l, int r, int x) {
    if (l > r) return -1;
    int m = (l + r) / 2;
    if (a[m] == x) return m;
    if (x < a[m]) return bs(a, l, m - 1, x);
    return bs(a, m + 1, r, x);
}
int main() {
    int n, x;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter %d sorted elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("Enter element to search: ");
    scanf("%d", &x);
    int i = bs(a, 0, n - 1, x);
    if (i == -1)
        printf("not found\n");
    else
        printf("found at %d\n", i);
    return 0;
}
