// Aim of the program: Write a program in C to convert the first ‘n’ decimal numbers of a disc
// file to binary using recursion. Store the binary value in a separate disc file.
#include <stdio.h>
int getMaxBitWidth(int nums[], int count) {
    int maxVal = nums[0];
    for (int i = 1; i < count; i++) {
        if (nums[i] > maxVal)
            maxVal = nums[i];
    }
    int bitsRequired = 0;
    while (maxVal > 0) {
        bitsRequired++;
        maxVal /= 2;
    }
    return bitsRequired;
}
void convertToBinary(int value, int binArray[], int pos) {
    if (pos >= 0) {
        binArray[pos] = value % 2;
        convertToBinary(value / 2, binArray, pos - 1);
    }
}
int main() {
    int input[100], size, limit;

    printf("Enter total number of elements in the array: ");
    scanf("%d", &size);

    printf("Enter %d decimal numbers:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &input[i]);
    }

    printf("Enter how many numbers (n) to convert to binary: ");
    scanf("%d", &limit);

    if (limit > size) {
        printf("n should not be greater than total array size.\n");
        return 1;
    }

    int bitWidth = getMaxBitWidth(input, limit); 
    printf("\nBinary equivalents with leading zeros (width = %d bits):\n", bitWidth);
    for (int i = 0; i < limit; i++) {
        int binResult[bitWidth];
        for (int j = 0; j < bitWidth; j++)
            binResult[j] = 0;
        convertToBinary(input[i], binResult, bitWidth - 1);

        printf("%d (decimal) = ", input[i]);
        for (int j = 0; j < bitWidth; j++)
            printf("%d", binResult[j]);
        printf(" (binary)\n");
    }
    return 0;
}
