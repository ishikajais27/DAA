//Write a function to ROTATE_RIGHT(p1,p2) right an array for first p2 elements by position using EXCHANGE(p,q) 
//function to swap the numbers p and q.Parameter p1 be the starting address of the array and p2 be the number of
//elements to be rotated
#include <stdio.h>

void exchange(int *p, int *q) {
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}

void rotate_right(int *p1, int p2) {
    int i;
    for(i = p2 - 1; i > 0; i--) {
        exchange(&p1[i], &p1[i - 1]);
    }
}

int main() {
    int num[100], n, i, pos;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d numbers: ", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }

    printf("Enter how many first elements to rotate: ");
    scanf("%d", &pos);

    rotate_right(num, pos);

    printf("Array after rotating first %d elements to right:\n", pos);
    for(i = 0; i < n; i++) {
        printf("%d ", num[i]);
    }

    return 0;
}
