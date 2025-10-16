//wap to sort n number of inputs using bubble sort(inputs more than 500) using random function take these inputs,
//WAP to sort using insertion sort and take input using rand function
//WAP to implement selection sort take inputs using random function
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gen(int a[], int n) {
    for (int i = 0; i < n; i++)
        a[i] = rand() % 1000;
}

void bub(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
}

void ins(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int k = a[i], j = i - 1;
        while (j >= 0 && a[j] > k) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = k;
    }
}

void sel(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int m = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[m])
                m = j;
        }
        int t = a[i];
        a[i] = a[m];
        a[m] = t;
    }
}

void dis(int a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int a[10000], n, ch;
    srand(time(0));
    while (1) {
        printf("\nEnter how many numbers to sort (min 10, max 10000): ");
        scanf("%d", &n);
        if (n < 10 || n > 10000) {
            printf("Invalid size\n");
            continue;
        }

        printf("1.Bubble 2.Insertion 3.Selection 4.Exit\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                gen(a, n);
                bub(a, n);
                dis(a, n);
                break;
            case 2:
                gen(a, n);
                ins(a, n);
                dis(a, n);
                break;
            case 3:
                gen(a, n);
                sel(a, n);
                dis(a, n);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid\n");
        }
    }
}
