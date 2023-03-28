/*You have been given two sorted integer arrays of size m and n. Design an algorithm and
implement it using a program to find list of elements which are common to both. (Time
Complexity = O(m+n))*/
#include <stdio.h>

int find_common_elements(int* A, int* B, int m, int n, int* common_elements) {
    int i = 0, j = 0, k = 0;
    while (i < m && j < n) {
        if (A[i] == B[j]) {
            common_elements[k++] = A[i];
            i++;
            j++;
        } 
        else if (A[i] < B[j]) {
            i++;
        } 
        else {
            j++;
        }
    }
    return k;
}

int main() {
    int m, n, t;
    printf("Enter no of test cases : ");
    scanf("%d",&t);
    for(int j=0;j<t;j++){
        printf("Enter the size of array1: ");
        scanf("%d", &m);
        printf("Enter the elements of array1 in sorted order: ");
        int array1[m];
        for (int i = 0; i < m; i++) {
            scanf("%d", &array1[i]);
        }
        printf("Enter the size of array2: ");
        scanf("%d", &n);
        printf("Enter the elements of array2 in sorted order: ");
        int array2[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &array2[i]);
        }
        int common_elements[m+n];
        int num_common_elements = find_common_elements(array1, array2, m, n, common_elements);
        if (num_common_elements > 0) {
            printf("Common elements: ");
            for (int i = 0; i < num_common_elements; i++) {
                printf("%d ", common_elements[i]);
            }
            printf("\n");
        } 
        else {
            printf("No common elements found.\n");
        }
    }
    return 0;
}
