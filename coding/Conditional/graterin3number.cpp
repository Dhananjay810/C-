#include<iostream>
using namespace std;
int main(){
    int a,b,c;
    cout<<"enter 1st no. :";
    cin>>a;
    cout<<"enter 2nd no. :";
    cin>>b;
    cout<<"enter 3rd no. :";
    cin>>c;
    if(a>b && a>c){
        cout<<a<<" is the greatest one";
    }
    if(b>a && b>c){
        cout<<b<<" is the greatest one";
    }
    if(c>a && c>a){
        cout<<c<<" is the greatest one";
    }


}