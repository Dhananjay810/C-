#include<iostream>
using namespace std;
int main(){
    int a;
    cout<<"enter a no. :";
    cin>>a;
    if(a>=100 && a>=999){
        cout<<"yes it is three digit no.";
    }
    else{
        cout<<"no it is non three digit no.";
    }
}