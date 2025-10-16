//Find best case and worst case time complexity of all sorting of (10-1000 or more ) inputs in c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5000  

void bubbleSortRenamed(int array[], int length) {
    int i, j, tempVar;
    for(i = 0; i < length - 1; i++) {
        for(j = 0; j < length - i - 1; j++) {
            if(array[j] > array[j + 1]) {
                // Swap
                tempVar = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tempVar;
            }
        }
    }
}

int main() {
    int sortedInput[SIZE], reversedInput[SIZE];
    clock_t begin, finish;
    double elapsedTime;

  
    for(int i = 0; i < SIZE; i++) {
        sortedInput[i] = i;
    }


    for(int i = 0; i < SIZE; i++) {
        reversedInput[i] = SIZE - i;
    }

    begin = clock();
    bubbleSortRenamed(sortedInput, SIZE);
    finish = clock();
    elapsedTime = ((double)(finish - begin)) / CLOCKS_PER_SEC;
    printf("Time taken for Best Case (already sorted): %f seconds\n", elapsedTime);


    begin = clock();
    bubbleSortRenamed(reversedInput, SIZE);
    finish = clock();
    elapsedTime = ((double)(finish - begin)) / CLOCKS_PER_SEC;
    printf("Time taken for Worst Case (reverse sorted): %f seconds\n", elapsedTime);

    return 0;
}
