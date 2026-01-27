#include<stdio.h>
int main(){
    int arr[]={2,3,5,6,8,9,1,4,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    int minindex;
    int temp;
    for(int i=0;i<n-1;i++){
       minindex=i;
       for(int j=i+1;j<n;j++){
        if(arr[j]<arr[minindex]){
            minindex=j;
        }
       }
       temp=arr[i];
       arr[i]=arr[minindex];
       arr[minindex]=temp;
    }
    printf("sorted array");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}