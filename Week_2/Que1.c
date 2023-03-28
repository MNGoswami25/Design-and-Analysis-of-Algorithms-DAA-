/*Given a sorted array of positive integers containing few duplicate elements, design an algorithm
and implement it using a program to find whether the given key element is present in the array or
not. If present, then also find the number of copies of given key. (Time Complexity = O(log n))*/#include<stdio.h>
int linear_search(int* A,int k,int n,int* count){
    int i,flag=-1;
    *count=0;
    for(i=0;i<n;i++){
        if(A[i]==k){
            flag=0;
            *count=*count+1;
        }
    }
    return flag;
}
int main(){
    int t,n,arr[50],k,count;
    printf("Enter Number of test Cases: ");
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        printf("Enter Size of an Array : ");
        scanf("%d",&n);
        printf("Enter Elements in Sorted Order\n");
        for(int j=0;j<n;j++){
            scanf("%d",&arr[j]);
        }
        printf("Enter key to  Search : ");
        scanf("%d",&k);
        int c=linear_search(arr,k,n,&count);
        if(c!=-1){
            printf("%d -> %d\n",k,count);
        }
        else{
            printf("Key %d not present. \n",k);
            printf("Total comparision %d\n",count);
        }
    }
}
