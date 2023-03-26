/*Given an unsorted array of positive integers, design an algorithm and implement it using a
program to find whether there are any duplicate elements in the array or not. (use sorting) (Time
Complexity = O(n log n))*/
#include<stdio.h>
int s,c;
int Find(int* A,int n){
   
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
        int m=Find(arr,n);
        if(m!=-1){
            printf("YES");
        }
        else{
            printf("NO");
        }

    }
}