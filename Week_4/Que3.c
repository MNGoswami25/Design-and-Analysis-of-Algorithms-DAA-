/*Given an unsorted array of integers, design an algorithm and implement it using a program to
find Kth smallest or largest element in the array. (Worst case Time Complexity = O(n))*/
#include <stdio.h>
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}
int quick_select(int arr[], int low, int high, int k) {
    if (low == high) {
        return arr[low];
    }
    int pivot = partition(arr, low, high);
    int pivot_rank = pivot - low + 1;
    if (k == pivot_rank) {
        return arr[pivot];
    } else if (k < pivot_rank) {
        return quick_select(arr, low, pivot - 1, k);
    } else {
        return quick_select(arr, pivot + 1, high, k - pivot_rank);
    }
}

int main() {
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
        printf("Enter the value of k: ");
        scanf("%d",&k);
    int kth_smallest = quick_select(arr, 0, n- 1, k);
    printf("%d\n",kth_smallest);
}

}