/*Given an unsorted array of integers, design an algorithm and implement it using a program to
sort an array of elements by dividing the array into two subarrays and combining these subarrays
after sorting each one of them. Your program should also find number of comparisons and
inversions during sorting the array.*/
#include<stdio.h>
int s,c,n;
void merge(int A[],int p,int q,int r){
    int n1=q-(p+1);
    int n2=r-q;
    int L[n1],R[n2];
    for(int i=0;i<n1;i++){
        L[i]=A[p+i-1];
    }
    for(int j=0;j<n2;j++){
        R[j]=A[q+j];
    }
    L[n1]=1039300;
    R[n2]=193900;
     int i=0;
    int j=0;
    for(int k=p;k<r;k++){
        if(L[i]<=R[j]){
            A[k]=L[i];
            i++;
        }
        else{
            A[k]=R[j];
            j++;
        }
    }

}
void mergeSort(int A[],int l,int r){
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(A, l, m);
        mergeSort(A, m + 1, r);
        merge(A, l, m, r);
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
        mergeSort(arr,0,n-1);
        for(int j=0;j<n;j++){
            printf("%d ",arr[j]);
        }
        printf("\ncomparisons: %d",c);
        printf("\nshift: %d\n",s);

    }
}


