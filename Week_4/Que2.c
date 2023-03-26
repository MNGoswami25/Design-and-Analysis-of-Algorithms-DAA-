/*Given an unsorted array of integers, design an algorithm and implement it using a program to
sort an array of elements by partitioning the array into two subarrays based on a pivot element
such that one of the sub array holds values smaller than the pivot element while another sub
array holds values greater than the pivot element. Pivot element should be selected randomly
from the array. Your program should also find number of comparisons and swaps required for
sorting the array.*/
#include<stdio.h>
int s,c;
int partition(int A[],int p,int r){
    int x=A[r];
    int i=p-1;
    for(int j=p;j<r;j++){
        c++;
        if(A[j]<=x){
            i++;
            int temp=A[i];
            A[i]=A[j];
            A[j]=temp;
            s++;
        }
       
    }
     int temp=A[i+1];
        A[i+1]=A[r];
        A[r]=temp;
        s++;
    return i+1;
}
void quickSort(int A[],int p,int r){
    if(p<r){
        int q=partition(A,p,r);
        quickSort(A,p, q-1);
        quickSort(A, q+1, r);
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
        quickSort(arr,0,n-1);
        for(int j=0;j<n;j++){
            printf("%d ",arr[j]);
        }
        printf("\ncomparisons: %d",c);
        printf("\nswaps: %d\n",s);

    }
}

