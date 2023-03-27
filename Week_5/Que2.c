/*Given an unsorted array of integers, design an algorithm and implement it using a program to
find whether two elements exist such that their sum is equal to the given key element. (Time
Complexity = O(n log n))*/
#include<stdio.h>
void max_heapify(int A[],int n,int i){
    int l = 2 * i + 1;
    int r = 2 * i + 2,largest=i;
    if(l<n && A[l]>A[largest]){
        largest=l;
    }
    if(r<n && A[r]>A[largest]){
        largest=r;
    }
    if(largest!=i){
        int temp=A[i];
        A[i]=A[largest];
        A[largest]=temp;
        max_heapify(A,n, largest);
    }
}
   
void build_max_heap(int A[],int n){
    for(int i=n/2-1;i>=0;i--){
        max_heapify(A,n,i);
    }
}
void heapSort(int A[],int n){
   build_max_heap(A,n);
   for(int i=n-1;i>0;i--){
        int temp=A[0];
        A[0]=A[i];
        A[i]=temp;
        max_heapify(A,i,0);
   }
}
int main(){
    int t,n,arr[50];
    printf("Enter Number of test Cases: ");
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        printf("\nEnter Size of an Array : ");
        scanf("%d",&n);
        printf("Enter Elements\n");
        for(int j=0;j<n;j++){
            scanf("%d",&arr[j]);
        }
        heapSort(arr,n);
        int key;
        printf("Enter key : ");
        scanf("%d",&key);
        int k=n-1,j=0,flag=0;
        while(j<k){
            if(arr[j]+arr[k]==key){
                flag=1;
                break;
            }
            else if(arr[j]+arr[k]<key){
                j++;
            }
            else{
                k--;
            }
        }
        if(flag==1){
            printf("%d  %d",arr[j],arr[k]);
        }
        else{
            printf("No Such Element Exixt");
        }
        

    }
}


