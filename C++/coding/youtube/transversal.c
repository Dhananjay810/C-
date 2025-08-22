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
    printf("array is: ");
    for(int i=0; i<n; i++){
        printf("%d ",a[i]);
    }
}