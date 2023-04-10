/*Given an unsorted array of integers, design an algorithm and implement it using a program to
find Kth smallest or largest element in the array. (Worst case Time Complexity = O(n))*/
#include <stdio.h>
void countsort(int arr[],int n,int max,int b[])
{
    int i=0;
    int c[max];
    for(i=0;i<=max;i++)
    {
        c[i]=0;
    }
    for(i=0;i<n;i++)
    {
       c[arr[i]]=c[arr[i]]+1;
    }
    for(i=1;i<=max;i++)
    {
        c[i]=c[i]+c[i-1];
    }
    for(i=n-1;i>=0;i--)
    {
       c[arr[i]]--;
        b[c[arr[i]]]=arr[i];
         
    }
}
int main() {
     int t,n,arr[50],k,b[50],j;
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
        int max=arr[0];
        for(j=0;j<n;j++)
        {
            if(arr[j]>max)
            {
                max=arr[j];
            }
        }
         countsort(arr,n,max,b);
        printf("\nKth Smallest : %d\n",b[k-1]);
        printf("Kth largest: %d\n",b[n-k-1]);
    }

}