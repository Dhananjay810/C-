#include<stdio.h>
#include<stdlib.h>
struct cirque{
    int f;
    int r;
    int size;
    int*arr;
};
void createq(struct cirque*cq,int cap){
    cq->size=cap;
    cq->f=-1;
    cq->r=-1;
    cq->arr=malloc(cap*sizeof(int));
}
int siize(struct cirque*cq){
    int s=cq->size-cq->f+cq->r+1;
    s=s%cq->size;
    return s;
}
int isFull(struct cirque*cq){
    if(siize(cq)/(cq->size)==1 && siize(cq)%(cq->size)==0) return 1;
    return 0;
}
int isEmpty(struct cirque*cq){
    if(siize(cq)==0) return 1;
    else if(cq->f==cq->r && (cq->r==0 || cq->r==-1)) return 1;
    return 0;
}
void enqueue(struct cirque*cq,int data){
    if(isEmpty(cq)==1){
        if(cq->f==-1){
            cq->f++;
            cq->r++;
            cq->arr[cq->r]=data;
        }
        else{
            cq->r++;
            cq->arr[cq->r]=data;
        }
    }
    else{
        if(isFull(cq)==1) printf("queue is full\n");
        else if(cq->r==cq->size-1 && isFull(cq)!=1){
            cq->r=0;
            cq->arr[cq->r]=data;
            printf("data is entered\n");
        }
        else{
            cq->r++;
            cq->arr[cq->r]=data;
            printf("data is entered\n");
        }
    }
}
void dequeue(struct cirque*cq){
    if(isEmpty(cq)==1) printf("queue is empty\n");
    else if(cq->f==cq->size-1 && isEmpty(cq)!=1){
        printf("%d is deleted\n",cq->arr[cq->f]);
        cq->f=0;
    }
    else{
        printf("%d is deleted\n",cq->arr[cq->f]);
        cq->f++;
    }
}
void peek(struct cirque*cq){
    if(isEmpty(cq)==1) printf("queue is empty\n");
    else{
        printf("%d is at peek\n",cq->arr[cq->f]);
    }
}
void rear(struct cirque*cq){
    if(isEmpty(cq)==1) printf("queue is empty\n");
    else{
        printf("%d is at peek\n",cq->arr[cq->r]);
    }
}
int main(){
    struct cirque*cq;
    printf("hey today we deal with stack\n");
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
    createq(cq,n);
    int t=1000;
    char ch;
    while(t>0){
        printf("enter character :\n");
        scanf("%c",&ch);
        switch(ch){
            case '@':{
                int data;
                printf("enter data which u want to store :");
                scanf("%d",&data);
                enqueue(cq,data);
                break;
            }
            case '#':{
                printf("%d\n",isEmpty(cq));
                break;
            }
            case '$':{
                printf("%d\n",isFull(cq));
                break;
            }
            case '~':{
                dequeue(cq);
                break;
            }
            case '(':{
                printf("%d is size\n",siize(cq));
                break;
            }
            case ')':{
                rear(cq);
                break;
            }
            case '[':{
                peek(cq);
                break;
            }
        }
        t--;
    }
}