#include<stdio.h>
int main(){
    int n;
    printf("enter no. of element in array : ");
    scanf("%d",&n);
    int a[n+1];
    printf("enter element: ");
    for(int i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    int x;
    printf("enter no. which u want to insert: ");
    scanf("%d",&x);
    int y;
    printf("enter index which u want to insert it: ");
    scanf("%d",&y);
    for(int i=n; i>=0; i--){
        if(i>y){
            a[i]=a[i-1];
        }
    }
    for(int i=0; i<n; i++){
        if(i==y){
            a[i]=x;
        }
    }
    for(int i=0; i<n+1; i++){
        printf("%d ",a[i]);
    }
}