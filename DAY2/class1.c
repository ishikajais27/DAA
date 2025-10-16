#include<stdio.h>
int gcd(int a, int b) {
    if(b == 0)
        return a;
    else
     return gcd(b, a % b);
}
int main(){
    int x, y, result;
    FILE *fp, *out;
    fp = fopen("class_demo.txt", "r");
    out = fopen("class_result.txt", "w");
    if(fp == NULL || out == NULL){
        printf("Invalid File");
    }
    else{
        while(fscanf(fp, "%d %d", &x, &y) == 2){
            result = gcd(x, y);
            fprintf(out, "GCD of %d and %d is %d\n", x, y, result);
            printf("GCD of %d and %d is %d\n", x, y, result);
        }
        fclose(fp);
        fclose(out);
    }
}
