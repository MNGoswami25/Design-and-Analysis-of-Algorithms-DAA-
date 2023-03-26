/*Given an unsorted array of integers, design an algorithm and implement a program to sort this
array using selection sort. Your program should also find number of comparisons and number of
swaps required.*/
#include<stdio.h>
int s,c;
void selection_sort(int* A,int n){
   int i, j, min_idx, temp;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
             c++;
            if (A[j] < A[min_idx]) {
                min_idx = j;
            }
        }
        temp = A[min_idx];
        A[min_idx] = A[i];
        A[i] = temp;
        s++;
    }
    
}
int main(){
    int t,n,arr[50];
    printf("Enter Number of test Cases: ");
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        s=0,c=0;
        printf("Enter Size of an Array : ");
        scanf("%d",&n);
        printf("Enter Elements\n");
        for(int j=0;j<n;j++){
            scanf("%d",&arr[j]);
        }
        selection_sort(arr,n);
        for(int j=0;j<n;j++){
            printf("%d ",arr[j]);
        }
        printf("\ncomparisons: %d",c);
        printf("\nswap: %d\n",s);

    }
}