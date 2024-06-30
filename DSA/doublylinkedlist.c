#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node*next;
    struct node*prev;
};
struct node *ins(struct node*dll,int val,int data){
    struct node*b=malloc(sizeof(struct node));
        struct node*a;
        a=dll;
        while(a->info!=data){
            a=a->next;
        }
        b->next=a->next;
        b->prev=a;
        a->next=b;
        b->info=val;
        return dll;
}
struct node *begins(struct node*dll, int val){
    struct node *b=malloc(sizeof(struct node));
    b->info=val;
    b->next=dll;
    b->prev=NULL;
    dll=b;
}
struct node *del(struct node*dll,int data){
    struct node*a;
    a=dll;
    if(dll->info==data){
        printf("%d in deleted\n",dll->info);
        dll=dll->next;
        dll->prev=NULL;
    }
    else{
        while(a->info!=data){
            a=a->next;
        }
        printf("%d is deleted\n",a->info);
        a->prev->next=a->next;
        a->next->prev=a->prev;
    }
    return dll;
}
struct node *trans(struct node*dll){
    struct node*a;
    a=dll;
    do{
        printf("%d ",a->info);
        a=a->next;
    }while(a->next!=NULL);
    return dll;
}
int main(){
    struct node*dll;
    dll=NULL;
    printf("press '1' to insert node in beginning\n");
    printf("press '2' to insert node after data\n");
    printf("press '3' for delete\n");
    printf("press '4' print info\n");
    int f=500;
    while(f>0){
        int t;
        printf("enter digit which instruction u want to do :");
        scanf("%d",&t);
            if(t==1){
                int n;
                printf("enter data u want to store :");
                scanf("%d",n);
                dll=begins(dll,n);
                }
            else if(t==2){
                int n;
                printf("enter data u want to store :");
                scanf("%d",&n);
                int g;
                printf("enter info after which u want to store :");
                scanf("%d",&g);
                dll=ins(dll,n,g);}
            else if(t==3){
                int g;
                printf("enter data which u want to delete :");
                scanf("%d",&g);
                dll=del(dll,g);}
            else if(t==4){
                dll=trans(dll);}
        f--;
    }
    return 0;
}