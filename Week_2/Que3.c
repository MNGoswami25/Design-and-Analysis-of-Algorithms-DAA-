#include<stdio.h>
int linear_search(int* A,int k,int n){
    int i,count=0;
    for(i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(A[i]>A[j]){
                if(A[i]-A[j]==k){
                    count++;
                }
            }
            else{
                if(A[j]-A[i]==k){
                    count++;
                }
            }
        }
    }
    return count;
}
int main(){
    int t,n,arr[50],k;
    printf("Enter Number of test Cases: ");
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        printf("Enter Size of an Array : ");
        scanf("%d",&n);
        printf("Enter Elements\n");
        for(int j=0;j<n;j++){
            scanf("%d",&arr[j]);
        }
        printf("Enter key (Difference): ");
        scanf("%d",&k);
        int c=linear_search(arr,k,n);
        printf("Total Pairs %d\n",c);
    }
}