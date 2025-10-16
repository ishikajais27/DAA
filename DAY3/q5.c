//Write a recursive program for Linear search
#include <stdio.h>
int ls(int a[], int n, int x, int i) {
    if (i >= n) return -1;
    if (a[i] == x) return i;
    return ls(a, n, x, i + 1);
}
int main() {
    int n, x;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("Enter element to search: ");
    scanf("%d", &x);
    int r = ls(a, n, x, 0);
    if (r == -1)
        printf("not found\n");
    else
        printf("found at %d\n", r);
    return 0;
}
