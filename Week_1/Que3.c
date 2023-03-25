#include<stdio.h>
#include<math.h>
int jumpSearch(int arr[], int k, int n,int* c){
    *c=0;
    int block_size = sqrt(n);
    int left = 0;
    int right = block_size;
    while (right <n && k>arr[left] && k>arr[right]) {
        *c=*c+1;
        left = right;
        right =right+block_size;
    }
    for (int i = left; i<=right; i++) {
         *c=*c+1;
        if (arr[i] == k) {
            return i;
        }
    }
    return -1;
}
int main(){
    int t,n,arr[50],k,cmp=0;
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
        int c=jumpSearch(arr,k,n,&cmp);
        if(c!=-1){
            printf("Present\n");
            printf("Total comparision %d\n",cmp);
        }
        else{
            printf("Not Present \n");
            printf("Total comparision %d\n",cmp);
        }
    }
}
