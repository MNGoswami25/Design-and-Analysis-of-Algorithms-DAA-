/*Given a sorted array of positive integers containing few duplicate elements, design an algorithm
and implement it using a program to find whether the given key element is present in the array or
not. If present, then also find the number of copies of given key. (Time Complexity = O(log n))*/
#include<stdio.h>
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    int count = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) {
            count++;
            int left = mid - 1, right = mid + 1;
            while (left >= 0 && arr[left] == key) {
                count++;
                left--;
            }
            while (right < n && arr[right] == key) {
                count++;
                right++;
            }
            return count;
        }
        else if (arr[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return 0;
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
         int c = binarySearch(arr, n, k);
        if(c!=0){
            printf("%d -> %d\n",k,c);
        }
        else{
            printf("Key %d not present. \n",k);
        }
    }
}

