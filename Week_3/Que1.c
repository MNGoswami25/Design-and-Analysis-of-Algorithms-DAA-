/*I. Given an unsorted array of integers, design an algorithm and a program to sort the array using
insertion sort. Your program should be able to find number of comparisons and shifts ( shifts -
total number of times the array elements are shifted from their place) required for sorting the
array.*/
#include<stdio.h>
int s,c;
void insertion_sort(int* A,int n){
   int i, j, key;
    for (i = 1; i < n; i++) {
        key = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > key) {
            c++;
            A[j+1] = A[j];
            s++;
            j--;
        }
        A[j+1] = key;
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
        insertion_sort(arr,n);
        for(int j=0;j<n;j++){
            printf("%d ",arr[j]);
        }
        printf("\ncomparisons: %d",c);
        printf("\nshift: %d\n",s);

    }
}