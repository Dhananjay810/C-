#include<stdio.h>

int main(){
    int marks[]={12, 13, 11};
    int *ptr;
    *ptr=&marks[1];
    int *_ptr=&marks[0];
    printf("%d", *ptr);
    printf("%d", *_ptr);
    return 0;
}