#include<stdio.h>
#define MAX 1000
void radix(int *,int );
int countMaxDig(int *,int);
void countingSort(int *,int,int);
int main(){
    int arr[] = {170,230,9,56,72,1356,789,129087,4,5,6,22,43},i,n;
    n = sizeof(arr)/sizeof(arr[0]);
    printf("Unsorted array is \n");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    radix(arr,n);
    printf("Array after sorting\n");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}
int countMaxDig(int *arr,int n){
    int i,max=0,countDig=0;
    for(i=0;i<n;i++){
        if(arr[i]>max)
            max=arr[i];
    }
//    printf("max = %d\n",max);
    while(max){
        countDig++;
        max = max/10;
    }
    return countDig;
}
void radix(int *arr, int n){
    int i,exp,maxDig;
    maxDig=countMaxDig(arr,n);
//    printf("Maximum no. of digits in input is %d\n",maxDig);
    for(exp=1,i=0;maxDig--;exp*=10){
//        printf("\nFor iteration %d, exp is %d",i++,exp);
        countingSort(arr,n,exp);
    }
}

void countingSort(int *arr, int n, int exp){
    int count[10],i,output[MAX];
    for(i=0;i<10;i++){
        count[i] = 0;
    }
    for(i=0;i<n;i++){
        count[(arr[i]/exp)%10]++;
    }
/*
    printf("\nCount array is\n");
    for(i=0;i<10;i++)
        printf("%d ",count[i]);
    printf("\n");
*/
    
    for(i=1;i<10;i++)
        count[i]+=count[i-1];

/*
    printf("\nCount array is\n");
    for(i=0;i<10;i++)
        printf("%d ",count[i]);
    printf("\n");
*/    
    
    for(i=n-1;i>=0;i--){
        output[count[((arr[i]/exp)%10)]-1]=arr[i];
        count[(arr[i]/exp)%10]--;
    }
/* 
    printf("\nArray inside counting sort\n");
    for(i=0;i<n;i++){
        printf("%d ",output[i]);
    }
    printf("\n");
*/

    for(i=0;i<n;i++)
        arr[i]=output[i];
}
