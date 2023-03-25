#include<stdio.h>
int binarySearch(int arr[], int k, int n,int* c){
    int start = 0, end = n - 1, mid;
    *c = 0;
    while (start <= end) {
        mid = (start + end) / 2;
        *c=*c+1;
        if (arr[mid] == k) {
            return mid;
        }
        else if (k < arr[mid]) {
            end = mid - 1;
        }
        else {
            start = mid + 1;
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
        int c=binarySearch(arr,k,n,&cmp);
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
