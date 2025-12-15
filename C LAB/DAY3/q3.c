//Write a recursive program to calculate the sum of n numbers
#include <stdio.h>

int sum(int arr[], int n) {
    if (n == 0)
        return 0;
    return arr[n - 1] + sum(arr, n - 1);                                                    
}
int main() {
    int arr[100], n, i, res;
    printf("enter size: ");
    scanf("%d", &n);
    printf("enter elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    res = sum(arr, n);
    printf("sum is %d\n", res);
    return 0;
}
