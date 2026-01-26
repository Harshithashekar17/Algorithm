#include<stdio.h>
#define N 10
int parent[N];
int rankarr[N];
void makeset(int n){
    for(int i=0;i<n;i++){
        parent[i]=i;
        rankarr[i]=0;
    }
}
int find(int x){
    if(parent[x]!=x){
        parent[x]=find(parent[x]);
    }
    return parent[x];
}
void unionsets(int a,int b){
    a=find(a);
    b=find(b);
    if(a!=b){
        if(rankarr[a]<rankarr[b]){
            parent[a]=b;
        }
        else if(rankarr[b]>rankarr[a]){
            parent[b]=a;
        }
        else{
            parent[b]=a;
            rankarr[a]++;
        }
    }
}
int main(){
    int n=6;
    makeset(n);
    unionsets(0,1);
    unionsets(1,2);
    unionsets(3,4);
    printf("Find(2)=%d\n",find(2));
    printf("Find(4)=%d\n",find(4));
    printf("Find(5)=%d\n",find(5));
    return 0;
}