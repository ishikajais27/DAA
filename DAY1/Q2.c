//Given an array ar[] of size N, find the prefix sum of array. A prefix sum array is another array prefixSum[] of the same size,
// such that the value of the prefixSum[]is arr[0]+arr[1]+...........+arr[j].
#include<stdio.h>
int main(){
    int N;
    printf("Enter size of an array- ");
    scanf("%d",&N);
    int arr[N];
    int prefixSum[N];
    int sum;
    printf("Enter the elements of the array- ");
    for(int i=0;i<N;i++){
        scanf("%d",&arr[i]);
    }
    prefixSum[0]=arr[0];
    sum=arr[0];
    for(int i=1;i<N;i++){
        sum+=arr[i];
        prefixSum[i]=sum;
    }
    printf("The prefix sum array- ");
    for(int i=0;i<N;i++){
        printf(" %d ",prefixSum[i]);
    }
}