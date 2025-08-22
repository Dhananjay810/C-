#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node*next;
};
struct node *begin(struct node *cll,int val){
    struct node*b=malloc(sizeof(struct node));
    if(cll==NULL){
        b->info=val;
        cll=b;
        b->next=b;
    }
    else{
        struct node*a=cll;
        struct node*c=cll;
        while(a->next!=c){
            a=a->next;
        }
        b->info=val;
        b->next=cll;
        cll=b;
        a->next=b;
    }
    return cll;
}
struct node * del(struct node*cll,int data){
    struct node*a=cll;
    if(a->info==data){
        struct node*b=cll;
        struct node*c=cll;
        while(b->next!=c){
            b=b->next;
        }
        printf("%d is deleted\n",a->info);
        b->next=a->next;
    }
    else{
    while(a->next->info!=data){
        a=a->next;
    }
    printf("%d is deleted\n",a->next->info);
    a->next=a->next->next;
    }
    return cll;
}
struct node*trav(struct node*cll){
    struct node*a=cll;
    struct node*b=cll;
    do{
        printf("%d ",a->info);
        a=a->next;
    }while(a!=b);
    return cll;
}
struct node *ins(struct node*cll,int data,int val){
    struct node*a;
    a=cll;
    struct node*b=malloc(sizeof(struct node));
    while(a->info!=data){
        a=a->next;
    }
    b->info=val;
    b->next=a->next;
    a->next=b;
    return cll;
}
int main(){
    struct node*cll;
    cll=NULL;
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
            cll=begin(cll,n);
        }
        if(ch=='@'){
            int n;
            printf("enter val : ");
            scanf("%d",&n);
            int m;
            printf("enter data : ");
            scanf("%d",&m);
            cll=ins(cll,m,n);
        }
        if(ch=='#'){
            int n;
            printf("enter data : ");
            scanf("%d",&n);
            cll=del(cll,n);
        }
        if(ch=='$'){
            cll=trav(cll);
        }
        t--;
    }
}