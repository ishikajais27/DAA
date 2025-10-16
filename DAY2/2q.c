// Aim of the program: Write a program in C to find GCD of two numbers using recursion.
// Read all pair of numbers from a file and store the result in a separate file.
#include <stdio.h>
int findGCD(int a, int b) {
    int gcd = 1;
    int i;
    for(i = 1; i <= a && i <= b; i++) {
        if(a % i == 0 && b % i == 0) {
            gcd = i;
        }
    }
    return gcd;
}
int main(){
    int n1, n2;
    printf("Enter two numbers- ");
    scanf("%d %d", &n1, &n2);
    int result=findGCD(n1,n2);
    printf("GCD of given two numbers-> %d",result);
    
    return 0;
}
