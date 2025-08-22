#include<stdio.h>
#include<stdlib.h>
struct arraySt {
int top ;
int capacity;
char*ptr;};

void createStack(int cap,struct arraySt* stack){
stack->ptr = malloc(cap*sizeof(char));
stack->top=-1;
stack->capacity=cap;
}
void push(struct arraySt* stack,int val){
*stack->ptr = val;
stack->top = stack->top + 1;
stack->ptr++ ;}
void pop(struct arraySt* stack){
while(1){
stack->ptr-- ;
if(*stack->ptr != '('){
printf("%c",*stack->ptr);}
else{
break;}


}}
int main (){
struct arraySt* stack = (struct arraySt*)malloc(sizeof(struct arraySt));
int n;
printf("the size of operation : ");
scanf("%d",&n);
char ch[n+3];
ch[0]='(';
ch[n+2]=')';
for(int i =1;i<n+2;i++){
scanf("%c",&ch[i]);
}
createStack(n+3,stack);
for(int i = 0; i<n+3;i++){
if(ch[i]=='+'||ch[i]=='-'||ch[i]=='/'||ch[i]=='*'||ch[i]=='('){
push(stack,ch[i]);
}
else if(ch[i]==')'){
pop(stack);}
else{
printf("%c",ch[i]);}}
return 0;}