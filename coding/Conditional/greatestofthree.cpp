#include<iostream>
using namespace std;
int main(){
    int a,b,c;
    cout<<"a = ";
    cin>>a;
    cout<<"b = ";
    cin>>b;
    cout<<"c = ";
    cin>>c;
    if(a>b){
        if(a>c){
            cout<<"a is greatest";
        }
    }
    if(b>c){
        if(b>c){
            cout<<"b is greatest";
        }
    }
    if(c>a){
        if(c>b){
            cout<<"c is greatest"
        }
    }
    
}