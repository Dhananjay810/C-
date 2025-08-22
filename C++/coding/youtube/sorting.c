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
    for(int i=0; i<n; i++){
        for(int j=0; j<n-1-i; j++){
            if(a[j]>a[j+1]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    printf("Sorted array is : ");
    for(int i=0; i<n; i++){
        printf("%d ",a[i]);
    }
}