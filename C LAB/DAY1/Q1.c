//WAP to find out the second smallest and second largest element stored in an array of n integer 
#include<stdio.h>
int main(){
    int n;
    printf("Enter the size of the array- ");
    scanf("%d",&n);
    int arr[n];
    printf("enter the elements of array- ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int max_01 = arr[0];
    int max_02 = -1; 
    for(int i=0;i<n;i++){
        if(max_01 < arr[i]){
            max_01 = arr[i];
        }
    }
    for(int i=0;i<n;i++){
        if(arr[i] != max_01){
            if(max_02 == -1 || arr[i] > max_02){
                max_02 = arr[i];
            }
        }
    }
    int min_01 = arr[0];
    int min_02 = -1;
    for(int i=0;i<n;i++){
        if(min_01 > arr[i]){
            min_01 = arr[i];
        }
    }
    for(int i=0;i<n;i++){
        if(arr[i] != min_01){
            if(min_02 == -1 || arr[i] < min_02){
                min_02 = arr[i];
            }
        }
    }
    printf("Second Largest = %d\n", max_02);
    printf("Second Smallest = %d\n", min_02);
}
