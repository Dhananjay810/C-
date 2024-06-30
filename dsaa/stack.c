#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int size;
    int *arr;
    int top;
};

void createStack(struct stack*st,int length){
    st->arr=malloc(sizeof(int)*length);
    st->top=-1;
}

int isFull(struct stack*st){
    if(st->top==st->size-1) return 1;
    return 0;
}

int isEmpty(struct stack*st){
    if(st->top==-1) return 1;
    return 0;
}

void push(struct stack*st, int data){
    if(isFull(st)==1) printf("Stack is full");
    else{
        st->top++;
        printf("%d is pushed",data);
        st->arr[st->top]=data;
    }
}

void pop(struct stack*st){
    printf("%d is deleted",st->arr[st->top]);
    st->top--;
}

int main(){
    struct stack*st;
    printf("hey today we deal with stack\n");
    printf("press '@' to create stack\n");
    printf("press '#' to check is empty\n");
    printf("press '$' to check is full\n");
    printf("press '~' to push\n");
    printf("press '(' to pop\n");
    int y=500;
    while (y>0)
    {
        char c;
        printf("ennter command from above : ");
        scanf("%c",c);
        if(c=='@'){
            int d;
            printf("enter size");
            scanf("%d",&d);
            createStack(st,d);
        }
        else if(c=='#'){
            printf("%d\n",isEmpty(st));
        }
        else if(c=='$'){
            printf("%d",isFull(st));
        }
        else if(c=='~'){
            int s;
            printf("enter data: ");
            scanf("%d",&s);
            push(st,s);
        }
        else{
            pop(st);
        }
        y--;
    }
    
}