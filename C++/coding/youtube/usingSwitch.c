#include<stdio.h>
int main(){
    char h;
    printf("Enter * for traversal: \n");
    printf("Enter @ for insertion: \n");
    printf("Enter # for deletion: \n");
    printf("Enter ~ for sorting: \n");
    printf("Enter $ for searching: \n");
    scanf("%c",&h);
    switch (h)
    {
        case '*':{
            printf("Hey there, U select traversal\n");
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
            break;
        }
        case '@':{
            printf("Hey there, U select insertion\n");
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
            printf("enter index where u want to insert it: ");
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
            break;
        }
        case '#':{
            printf("Hey there, U select deletion\n");
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
            break;
        }
        case '~':{
            printf("Hey there, U select sorting\n");
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
            break;
        }
        case '$':{
            printf("Hey there, U select searching\n");
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
            break;
        }
    }
}