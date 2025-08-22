#include<iostream>
using namespace std;
int main(){
    int a,b;
    char q;
    cout<<"enter the problem : ";
    cin>>a>>q>>b;
    switch(q){
        case '+':
            cout<<a+b;break;
        case '-' :
            cout<<a-b;break;
        case '/' :
            cout<<a/b;break;
        case '*' :
            cout<<a*b;break;
    }
   
}