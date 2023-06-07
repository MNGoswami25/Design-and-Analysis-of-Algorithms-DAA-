#include <stdio.h>
#include <stdlib.h>


struct item {
    int value;  
    int weight; 
};

int compareItems(const void* a, const void* b) {
    double ratio1 = ((struct item*)a)->value / (double)((struct item*)a)->weight;
    double ratio2 = ((struct item*)b)->value / (double)((struct item*)b)->weight;
    if (ratio1 < ratio2) {
        return 1;
    } else if (ratio1 > ratio2) {
        return -1;
    } else {
        return 0;
    }
}

double fractionalKnapsack(int W, struct item arr[], int n,struct item nums[]) {

    qsort(arr, n, sizeof(struct item), compareItems);
    double totalProfit = 0;
    double remainingCapacity = W;
    for (int i = 0; i < n; i++) {
        if (arr[i].weight <= remainingCapacity) {
            remainingCapacity -= arr[i].weight;
            nums[i].weight=arr[i].weight;
            nums[i].value=i;
            totalProfit += arr[i].value;
        }
        else {
            totalProfit += remainingCapacity * ((double)arr[i].value / (double)arr[i].weight);
            break;
        }
    }
    return totalProfit;
}

int main() {
    int n,w;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    struct item arr[n],nums[n];
    printf("Enter the weight and value of each item: \n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &arr[i].weight, &arr[i].value);
    }
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &w);
    double maxProfit = fractionalKnapsack(w, arr, n,nums);
    printf("Maximum value that can be obtained from the knapsack = %.2lf\n", maxProfit);
    for(int i=0;i<n;i++){
        printf("%d--%d",nums[i].value,nums[i].weight);
    }
    return 0;
}
