#include<stdio.h>
#include<string.h>
int main(){
    struct pratik{
        char pratik[90];
        int pra;

    };
    struct pratik p1;
    p1.pra=54;
    strcpy(p1.pratik,"partik bharwa hai");
    printf("%d %s",p1.pra,p1.pratik);
}