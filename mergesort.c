#include<stdio.h>
void merge(int arr[],int left,int mid,int right){
    int i,j,k;
    int n1=mid-left+1;
    int n2=right-mid;
    int l[n1],r[n2];
    for(int i=0;i<n1;i++){
        l[i]=arr[left+i];
    }
    for(int i=0;i<n2;i++){
        r[i]=arr[mid+1+j];
    }
    i=0;
    j=0;
    k=left;
    while(i<n1 && j<n2){
        if(l[i]<=r[j]){
           arr[k]=l[i];
           i++;
        }
        else{
            arr[k]=r[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=l[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=r[j];
        j++;
        k++;
    }

}
void mergesort(int arr[],int left,int right){
    while(left<right){
        int mid=left+(right-left)/2;
        mergesort(arr,left,mid);
        mergesort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}
void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main(){
    int arr[]={38,27,43,3,9,82,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("before sorting");
    printArray(arr,n);
    mergesort(arr,0,n-1);
    printf("After sorting");
    printArray(arr,n);
    return 0;
}