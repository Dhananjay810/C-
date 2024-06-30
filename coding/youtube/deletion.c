#include<stdio.h>
int main(){
    int n;
    printf("enter no. of element in array : ");
    scanf("%d",&n);
    int a[n];
    printf("enter element: ");
    for(int i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    int x;
    printf("enter index from which u want to delete: ");
    scanf("%d",&x);
    for(int i=0; i<n; i++){
        if(i>=x){
            a[i]=a[i+1];
        }
    }
    for(int i=0; i<n-1; i++){
        printf("%d ",a[i]);
    }
}