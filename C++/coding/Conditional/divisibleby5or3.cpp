#include<iostream>
using namespace std;
int main(){
    int a; 
    cout<<"enter a no :";
    cin>>a;
    if(a%5==0 || a%3==0 ){ // if condition 1 is already true then compilie not go for condition2
            cout<<"divisible by one of  5 and 3";

    }
    else{
        cout<<"not divisible by both 5 and 3";
    }
}