#include<iostream>
using namespace std;
int main(){
    int a;
    cout<<"enter how many row : ";
    cin>>a;
    int b;
    cout<<"enter how many column : ";
    cin>>b;
    
    for(int i=1; i<=a; i++){
        
        for(int c=1; c<=b; c++){
            cout<<"*";
        }
        cout<<endl;
    }
}