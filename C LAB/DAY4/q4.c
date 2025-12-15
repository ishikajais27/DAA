#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4000  

void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;

    for(i = 0; i < n - 1; i++) {
        min_idx = i;
        for(j = i + 1; j < n; j++) {
            if(arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // Swap
        temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

int main() {
    int bestCase[SIZE], worstCase[SIZE];
    clock_t start, end;
    double time_taken;

    for(int i = 0; i < SIZE; i++) {
        bestCase[i] = i;
    }

    for(int i = 0; i < SIZE; i++) {
        worstCase[i] = SIZE - i;
    }

    start = clock();
    selectionSort(bestCase, SIZE);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for Best Case (already sorted): %f seconds\n", time_taken);

    start = clock();
    selectionSort(worstCase, SIZE);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for Worst Case (reverse sorted): %f seconds\n", time_taken);

    return 0;
}