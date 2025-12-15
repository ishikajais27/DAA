//WAP to read 'n' integer from a disc file hat must contain some duplicate and store them into an array. Perform
//(i)Find total number of duplicate elements in an array
//(ii)Finf the most repeating element in the array
#include <stdio.h>

int main() {
    int n, i, j, k;
    int num[100];
    int count[100];
    int total = 0;
    int max = 0;
    int most = 0;

    printf("Enter how many numbers: ");
    scanf("%d", &n);

    printf("Enter %d numbers: ", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }

    for(i = 0; i < n; i++) {
        count[i] = 1;
        for(j = i + 1; j < n; j++) {
            if(num[i] == num[j]) {
                count[i]++;
                for(k = j; k < n - 1; k++) {
                    num[k] = num[k + 1];
                }
                n--;
                j--;
            }
        }
    }

    for(i = 0; i < n; i++) {
        if(count[i] > 1) {
            total += count[i] - 1;
        }
        if(count[i] > max) {
            max = count[i];
            most = num[i];
        }
    }

    printf("Total duplicate numbers: %d\n", total);
    printf("Most repeating number: %d\n", most);

    return 0;
}
