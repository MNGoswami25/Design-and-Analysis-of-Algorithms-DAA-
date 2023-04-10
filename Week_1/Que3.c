/*Given an already sorted array of positive integers, design an algorithm and implement it using a
program to find whether a given key element is present in the sorted array or not. For an array
arr[n], search at the indexes arr[0], arr[2], arr[4],.....,arr[2k

] and so on. Once the interval (arr[2k
] <

key < arr[ 2k+1] ) is found, perform a linear search operation from the index 2k

to find the element
key. (Complexity < O(n), where n is the number of elements need to be scanned for searching):
Jump Search*/
// #include<stdio.h>
// #include<math.h>
// int jumpSearch(int arr[], int k, int n,int* c){
//     *c=0;
//     if(k<arr[0] ||k>arr[n-1]){
//         *c=*c+1;
//         return -1;
//     }
//     else{
//         int block_size = sqrt(n);
//          int left = 0;
//         int right = block_size;
//         while (k>arr[right]&& right<n) {
//             left = right;
//             right =right+block_size;
//         }
//         for (int i = left; i<=right; i++) {
//             *c=*c+1;
//             if (arr[i] == k) {
                
//                 return i;
//             }
//         }
//         return -1;
//      }
    
// }
// int main(){
//     int t,n,arr[50],k,cmp=0;
//     printf("Enter Number of test Cases: ");
//     scanf("%d",&t);
//     for(int i=0;i<t;i++){
//         printf("Enter Size of an Array : ");
//         scanf("%d",&n);
//         printf("Enter Elements in Sorted Order\n");
//         for(int j=0;j<n;j++){
//             scanf("%d",&arr[j]);
//         }
//         printf("Enter key to  Search : ");
//         scanf("%d",&k);
//         int c=jumpSearch(arr,k,n,&cmp);
//         if(c!=-1){
//             printf("Present\n");
//             printf("Total comparision %d\n",cmp);
//         }
//         else{
//             printf("Not Present \n");
//             printf("Total comparision %d\n",cmp);
//         }
//     }
// }
#include<stdio.h>
#include<math.h>

int jumpSearch(int arr[], int k, int n, int* c) {
    *c = 0;
    if (k < arr[0] || k > arr[n-1]) {
        (*c)++;
        return -1;
    }
    else {
        int block_size = sqrt(n);
        int left = 0;
        int right = block_size;
        while (right < n && k > arr[right]) {
            left = right;
            right += block_size;
            (*c)++;
        }
        for (int i = left; i <= right && i < n; i++) {
            (*c)++;
            if (arr[i] == k) {
                return i;
            }
        }
        return -1;
    }
}

int main() {
    int t, n, arr[50], k, cmp;
    printf("Enter Number of test Cases: ");
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        printf("Enter Size of an Array : ");
        scanf("%d", &n);
        printf("Enter Elements in Sorted Order\n");
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[j]);
        }
        printf("Enter key to Search : ");
        scanf("%d", &k);
        cmp = 0;
        int c = jumpSearch(arr, k, n, &cmp);
        if (c != -1) {
            printf("Present\n");
            printf("Total comparisons: %d\n", cmp);
        }
        else {
            printf("Not Present\n");
            printf("Total comparisons: %d\n", cmp);
        }
    }
    return 0;
}

