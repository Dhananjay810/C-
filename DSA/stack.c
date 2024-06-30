#include<stdio.h>
#include<stdlib.h>
struct stack{
    int top;
    int size;
    int *arr;
};
void createstack(struct stack*s,int cap){
    s->arr=malloc(sizeof(int)*cap);
    s->top=-1;
}
int isEmpty(struct stack*s){
    if(s->top==-1) return 1;
    else return 0; 
}
int isFull(struct stack*s){
    if(s->top==s->size-1) return 1;
    else return 0;
}
void push(struct stack*s,int data){
    if(isFull(s)==1) printf("Stack is full\n");
    else{
        s->top++;
        s->arr[s->top]=data;
        printf("data is pushed\n");
    }
}
void pop(struct stack*s){
    if(isEmpty(s)==1) printf("stack is empty\n");
    else{
        printf("%d is deleted",s->arr[s->top]);
        s->top--;
    }
}
int main(){
    struct stack*s;
    printf("hey today we deal with stack\n");
    printf("press '@' to create stack\n");
    printf("press '#' to check is empty\n");
    printf("press '$' to check is full\n");
    printf("press '~' to push\n");
    printf("press '(' to pop\n");
    int g=9;
    char ch;
    while(ch!='*'){
        printf("enter character :");
        scanf("%c",&ch);
        switch(ch){
            case '@':
            {int n;
            printf("enter capacity :");
            scanf("%d",&n);
            createstack(s,n);
            break;}
            case '#':
            {printf("%d\n",isEmpty(s));
            break;}
            case '$':
            {printf("%d\n",isFull(s));
            break;}
            case '~':
            {int data;
            printf("enter data u want to push :");
            scanf("%d",&data);
            push(s,data);
            break;}
            case '(':
           { pop(s);
            break;}
        }
    }
}