//Write a recursive program to find the gcd of two number and print it into another file
#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int main() {
    int a, b, result;
    FILE *fp;
    printf("enter two numbers: ");
    scanf("%d %d", &a, &b);
    result = gcd(a, b);
    fp = fopen("output.txt", "w");
    if (fp == NULL) {
        printf("error opening file\n");
        return 1;
    }
    fprintf(fp, "gcd of %d and %d is %d\n",a,b ,result);
    fclose(fp);
    return 0;
}
