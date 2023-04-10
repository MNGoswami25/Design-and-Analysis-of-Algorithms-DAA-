/*Given an unsorted array of positive integers, design an algorithm and implement it using a
program to find whether there are any duplicate elements in the array or not. (use sorting) (Time
Complexity = O(n log n))*/
#include<stdio.h>
void merge(int A[], int p, int q, int r){
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1+1], R[n2+1];
    for (int i = 0; i < n1; i++){
        L[i] = A[p + i];
    }
    for (int j = 0; j < n2; j++){
        R[j] = A[q + j + 1];
    }
    L[n1] = 2147483;
    R[n2] = 2147483;
    int i = 0;
    int j = 0;
    for (int k = p; k <= r; k++){  
        if (L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }
        else{
            A[k] = R[j];
            j++;
        }
        
    }
}

void mergeSort(int A[], int l, int r){
    if (l < r){
        int m = l + (r - l) / 2;
        mergeSort(A, l, m);
        mergeSort(A, m + 1, r);
        merge(A, l, m, r);
    }
}
int main(){
    int t,n,arr[50],j,i;
    printf("Enter Number of test Cases: ");
    scanf("%d",&t);
    for(i=0;i<t;i++){
        printf("Enter Size of an Array : ");
        scanf("%d",&n);
        printf("Enter Elements\n");
        for(j=0;j<n;j++){
            scanf("%d",&arr[j]);
        }
        mergeSort(arr, 0, n - 1);
        for(j=0;j<n-1;j++){
            
            if(arr[j]==arr[j+1]){
                printf("YES\n");
                break;
            }
        }
        if(j==n-1){
            printf("NO\n");
        }

    }
}