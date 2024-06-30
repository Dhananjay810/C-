#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node*next;
};
struct node *in(struct node*ll,int val,int data){
    struct node*a=ll;
    struct node*b=(struct node*)malloc(sizeof(struct node));
    while(a->info!=data){
        a=a->next;
    }
    b->next=a->next;
    b->info=val;
    a->next=b;
    return ll;
}
struct node *begin(struct node*ll,int val){
    struct node *b=(struct node *)malloc(sizeof(struct node));
    b->info=val;
    b->next=ll;
    ll=b;
    return ll;
}
struct node *del(struct node*ll,int data){
    struct node*b=ll;
    printf("HELLO\n");
    if(ll->info==data){
        printf("%d is deleted\n",ll->info);
        printf("NU");
        ll=ll->next;
    }
    else{
        while(b->next->info!=data){
            b=b->next;
        }
        printf("%d is deleted\n",b->next->info);
        b->next=b->next->next;
    }
    return ll;
}
struct node *travers(struct node*ll){
    if(ll==NULL) printf("There is no any node\n");
    else{
        while(ll!=NULL){
            printf("%d ",ll->info);
            ll=ll->next;
        }
    }
    return ll;
}
int main(){
    struct node*ll=NULL;
    printf("press '~' to insert node in beginning\n");
    printf("press '@' to insert node after data\n");
    printf("press '#' for delete\n");
    printf("press '$' print info\n");
    int f=1000;
    char ch;
    while(f>0){
        printf("enter character :");
        scanf("%c",&ch);
        switch (ch){
            case '~':{
                int n;
                printf("enter data :\n");
                scanf("%d",&n);
                ll = begin(ll,n);
                break;
            }
            case '@':{
                int n;
                printf("enter data :\n");
                scanf("%d",&n);
                int m;
                printf("enter no. after u insert :\n");
                scanf("%d",&m);
                ll = in(ll,n,m);
                break;
            }
            case '#':{
                int n;
                printf("enter data u want to delete :\n");
                scanf("%d",&n);
                ll = del(ll,n);
                break;
            }
            case '$':{
               ll = travers(ll);
            }
        }
    }
    f--;
}
