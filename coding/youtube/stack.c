#include<stdio.h>
#include<stdlib.h>
struct stack{
    int size;
    int top;
    int *arr;
};
void isEmpty(struct stack*ptr){
    if(ptr->top==-1) printf("stack is empty");
    else printf("stack is not empty");
}
int main(){
    struct stack *s;
    s->size=2;
    s->top=-1;
    s->arr=(int *)malloc(s->size*(sizeof(int)));
    isEmpty(s);
}