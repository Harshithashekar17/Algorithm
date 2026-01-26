#include<stdio.h>
void swap(int *a,int*b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int partion(int arr[],int low,int high){
    int pivot=arr[low];
    int i=low+1;
    int j=high;
    while(low<=high){
        while(i<=high && arr[i]<=pivot){
            i++;
        }
        while(arr[j]>pivot){
            j++;
        }
        if(i<=j){
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[low],&arr[j]);
    return j;
}
void quicksort(int arr[],int low,int high){
    if(low<high){
        int p=partion(arr,low,high);
        quicksort(arr,low,p-1);
        quicksort(arr,p+1,high);
    }
}
void printarr(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main(){
    int arr[]={38,27,43,3,9,82,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("before sorting");
    printarr(arr,n);
    printf("After swaping");
    quicksort(arr,0,n-1);
    printarr(arr,n);
    return 0;
}