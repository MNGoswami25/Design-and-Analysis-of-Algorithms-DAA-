/*Given an unsorted array of alphabets containing duplicate elements. Design an algorithm and
implement it using a program to find which alphabet has maximum number of occurrences and

print it. (Time Complexity = O(n)) (Hint: Use counting sort) */


#include<stdio.h>
int n;
void counting_sort(char* A,int c[],char max){
   for(int i=0;i<max-96;i++){
    c[i]=0;
   }
   for(int j=0;j<n;j++){
        c[A[j]-97]=c[A[j]-97]+1;
   }
}
int main(){
    int t;
    char arr[50], max='a';int c[50];
    printf("Enter Number of test Cases: ");
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        printf("Enter Size of an Array : ");
        scanf("%d",&n);
        printf("Enter Elements\n");
        fflush(stdin);
        for(int j=0;j<n;j++){
            scanf("%c",&arr[j]);
            fflush(stdin);
        }
        for(int j=0;j<n;j++){
            if(arr[j]>max){
                max=arr[j];
            }
        }
        counting_sort(arr,c,max);
        int m=1,index=-1;
        for(int j=0;j<max-97;j++){
            if(c[j]>m){
                m=c[j];
                index=j;
            }
        }
        if(m==1){
            printf("No Duplicate Present\n");
        }
        else{
             printf("%c->%d\n",index+97,m);
        }

    }
}