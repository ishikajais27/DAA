#include <stdio.h>

typedef struct {
    int id;
    float profit, weight, ratio;
} Item;

void swap(Item *a, Item *b) {
    Item t = *a; *a = *b; *b = t;
}

void heapify(Item arr[], int n, int i) {
    int largest = i, l = 2*i + 1, r = 2*i + 2;
    if(l < n && arr[l].ratio > arr[largest].ratio) largest = l;
    if(r < n && arr[r].ratio > arr[largest].ratio) largest = r;
    if(largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(Item arr[], int n) {
    for(int i = n/2 - 1; i >= 0; i--) heapify(arr, n, i);
    for(int i = n-1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int n, i;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    Item arr[n];
    for(i = 0; i < n; i++) {
        arr[i].id = i+1;
        printf("Enter the profit and weight of item no %d: ", i+1);
        scanf("%f %f", &arr[i].profit, &arr[i].weight);
        arr[i].ratio = arr[i].profit / arr[i].weight;
    }
    float cap;
    printf("Enter the capacity of knapsack:");
    scanf("%f", &cap);

    heapSort(arr, n);

    // After heapSort, array is sorted ascending; reverse for descending
    for(i = 0; i < n/2; i++) {
        Item t = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = t;
    }

    float totProfit = 0;
    float taken[n];
    for(i = 0; i < n; i++) taken[i] = 0;

    for(i = 0; i < n && cap > 0; i++) {
        if(arr[i].weight <= cap) {
            taken[i] = 1.0;
            cap -= arr[i].weight;
            totProfit += arr[i].profit;
        } else {
            taken[i] = cap / arr[i].weight;
            totProfit += arr[i].profit * taken[i];
            cap = 0;
        }
    }

    printf("Item No profit Weight Amount to be taken\n");
    for(i = 0; i < n; i++) {
        printf("%d %.6f %.6f %.6f\n", arr[i].id, arr[i].profit, arr[i].weight, taken[i]);
    }
    printf("Maximum profit: %.6f\n", totProfit);

    return 0;
}
