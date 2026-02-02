#include<stdio.h>
int gcd(int m,int n){
    if(n==0){
        return m; 
    }
    else{
        return gcd(n,m%n);
    }
}
int main(){
    int m,n;
    scanf("%d%d",&m,&n);
    int GCD=gcd(m,n);
    printf("GCD: %d",GCD);
    return 0;
}