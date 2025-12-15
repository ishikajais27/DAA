#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5000  

void insertionSort(int arr[], int n) {
    int i, key, j;
    for(i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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
    insertionSort(bestCase, SIZE);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for Best Case (already sorted): %f seconds\n", time_taken);

    
    start = clock();
    insertionSort(worstCase, SIZE);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for Worst Case (reverse sorted): %f seconds\n", time_taken);

    return 0;
}