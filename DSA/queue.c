#include<stdio.h>
#include<stdlib.h>
struct queue{
    int f;
    int r;
    int size;
    int*arr;
};
void createq(struct queue*q,int cap){
    q->size=cap;
    q->f=-1;
    q->r=-1;
    q->arr=malloc(q->size*sizeof(int));
}
int isEmpty(struct queue*q){
    if(q->f==-1 && q->r==-1) return 1;
    return 0;
}
int isFull(struct queue*q){
    if(q->r==q->size-1) return 1;
    return 0;
}
void enqueue(struct queue*q,int data){
    if(isFull(q)==1) printf("queue if full\n");
    else{
        if(isEmpty(q)==1) q->f++;
        q->r++;
        q->arr[q->r]=data;
    }
}
void dequeue(struct queue*q){
    if(isEmpty(q)==1 || q->f>q->r) printf("queue is empty\n");
    else{
        printf("%d is deleted",q->arr[q->f]);
        q->f++;
    }
}
void peek(struct queue*q){
    if(isEmpty(q)==1 || q->f>q->r) printf("queue is empty");
    else{
    printf("%d is at front\n",q->arr[q->f]);}
}
void rear(struct queue*q){
    if(isEmpty(q)==1 || q->f>q->r) printf("queue is empty");
    else{
    printf("%d is at rear\n",q->arr[q->r]);}
}
void size(struct queue*q){
    printf("%d is the size of queue",q->size);
}

int main(){
    struct queue*q;
    printf("hey today we deal with stack\n");
    printf("press '!' for create queue\n");
    printf("press '@' to Enqueue\n");
    printf("press '#' to check is empty\n");
    printf("press '$' to check is full\n");
    printf("press '~' to Dequeue\n");
    printf("press '(' to check size\n");
    printf("press ')' to check front element\n");
    printf("press '[' to check peek element\n");
    int n;
    printf("enter size :");
    scanf("%d",&n);
    createq(q,n);
    int t=1000;
    char ch;
    while(t>0){
        printf("enter character :");
        scanf("%c",&ch);
        switch(ch){
            case '@':{
                int data;
                printf("enter data which u want to store :");
                scanf("%d",&data);
                enqueue(q,data);
                break;
            }
            case '#':{
                printf("%d\n",isEmpty(q));
                break;
            }
            case '$':{
                printf("%d\n",isFull(q));
                break;
            }
            case '~':{
                dequeue(q);
                break;
            }
            case '(':{
                size(q);
                break;
            }
            case ')':{
                rear(q);
                break;
            }
            case '[':{
                peek(q);
                break;
            }
        }
        t--;
    }
}