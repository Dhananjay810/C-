#include<iostream>
using namespace std;
int main(){
     char str[]={'a','b','c','d','e'};
    for(int i=0; str[i]!='\0'; i++){
        cout<<str[i]<<" ";
    }
    cout<<endl;
    cout<<str<<" ";
    // char str[]={'a','b','c','d','e'};
    // cout<<str<<" ";
    // cout<<endl<<int(str[6]);
}