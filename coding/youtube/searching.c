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
    printf("enter no. which u want to search: ");
    scanf("%d",&x);
    int u=0;
    for(int i=0; i<n; i++){
        if(a[i]==x){
           printf("YES it is present");
           u=1;
        }
    }
    if(u==0){
        printf("NO it is not present");
    }
}