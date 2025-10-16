#include <stdio.h>
void decToBin(int n) {
    if (n == 0) {
        printf("0");
        return;
    }
    int bin[32];
    int i = 0;
     while (n > 0) {
        bin[i] = n % 2;
        n = n / 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", bin[j]);
    }
}
int main() {
    FILE *fp;
    int n, num;
    fp = fopen("demo01.txt", "r");
    if (fp == NULL) {
        printf("Unable to open file.\n");
        return 1;
    }
    printf("Enter number of elements to convert :");
    scanf("%d",&n);
    printf("Binary equivalents:\n");
    for (int i = 0; i < n; i++) {
        if (fscanf(fp, "%d", &num) != 1) {
            printf("Position not found at %d.\n", i);
            break;
        }
        printf("Decimal: %d => Binary: ", num);
        decToBin(num);
        printf("\n");
    }
    fclose(fp);
    return 0;
}
