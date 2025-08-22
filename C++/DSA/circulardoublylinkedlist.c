#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node*next;
    struct node*prev;
};
struct node *begin(struct node*cdll,int val){
    struct node*b=malloc(sizeof(struct node));
    if(cdll==NULL){
        b->info=val;
        cdll=b;
        b->next=b;
        b->prev=NULL;
    }
    else{
        struct node*a=cdll;
        struct node*c=cdll;
        while(a->next!=c) a=a->next;
        b->info=val;
        b->next=cdll;
        b->prev=NULL;
        cdll->prev=b;
        cdll=b;
        a->next=b;
    }
    return cdll;
}
struct node *ins(struct node*cdll,int data,int val){
    struct node*a=cdll;
    struct node*b=malloc(sizeof(struct node));
    while(a->info!=data) a=a->next;
    b->info=val;
    b->next=a->next;
    b->prev=a;
    a->next=b;
    return cdll;
}
struct node *del(struct node*cdll, int data){
    struct node*a=cdll;
    struct node*c=cdll;
    if(a->info==data){
        struct node*b;
        while(b->next!=c) b=b->next;
        printf("%d is deleted",a->info);
        b->next=a->next;
        a->next->prev=NULL;
    }
    else{
        struct node*b=cdll;
        while(b->next->info!=data){
            b=b->next;
        }
        printf("%d is deleted",b->next->info);
        b->next->next->prev=b;
        b->next=b->next->next;
    }
    return cdll;
}
struct node *trav(struct node*cdll){
    struct node*a=cdll;
    struct node*c=cdll;
    do{
        printf("%d ",a->info);
        a=a->next;
    }while(a!=c);
    return cdll;
}
int main(){
    struct node*cdll;
    cdll=NULL;
    printf("enter '~' for instert at begin\n");
    printf("enter '@' for instert\n");
    printf("enter '#' for deletion\n");
    printf("enter '$' for traversing\n");
    char ch;
    int t=4000;
    while(t>0){
        printf("enter input :");
        scanf("%c",&ch);
        if(ch=='~'){
            int n;
            printf("enter val : ");
            scanf("%d",&n);
            cdll=begin(cdll,n);
        }
        if(ch=='@'){
            int n;
            printf("enter val : ");
            scanf("%d",&n);
            int m;
            printf("enter data : ");
            scanf("%d",&m);
            cdll=ins(cdll,m,n);
        }
        if(ch=='#'){
            int n;
            printf("enter data : ");
            scanf("%d",&n);
            cdll=del(cdll,n);
        }
        if(ch=='$'){
            cdll=trav(cdll);
        }
        t--;
    }
}