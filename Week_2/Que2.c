/*Given a sorted array of positive integers, design an algorithm and implement it using a program
to find three indices i, j, k such that arr[i] + arr[j] = arr[k].*/
#include<stdio.h>
int binary_search(int arr[],int left, int right, int x){
    while (left <= right)
    {   int mid = (left + right) / 2;
        if (arr[mid] == x){
            return mid;
        }
        else if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}
void search(int* A,int* a,int* b ,int *c,int n){
    *a=-1,*b=-1,*c=-1;
    for(int i=0;i<n-2;i++){
        int j = i + 1;
        while (j < n && A[i] + A[j] <= A[n-1])
        {   int r = binary_search(A, j+1, n-1, A[i] + A[j]);
            if (r != -1)
               { *a=i+1;
                *b=j+1;
                *c=r+1;
                return;
            }
            j += 1;
        }
    }
}

int main(){
    int t,n,arr[50],count,a,b,c;
    printf("Enter Number of test Cases: ");
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        printf("Enter Size of an Array : ");
        scanf("%d",&n);
        printf("Enter Elements in Sorted Order\n");
        for(int j=0;j<n;j++){
            scanf("%d",&arr[j]);
        }
        search(arr,&a,&b,&c,n);
        if(a==-1){
            printf("No sequence found\n");
        }
        else{
            printf("%d %d %d\n",a,b,c);
        }
    }
}
