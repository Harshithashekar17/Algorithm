#include<stdio.h>
int main(){
    int arr[]={5,4,6,1,2,8,7,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    int temp;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    printf("sorted array:");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}