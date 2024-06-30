#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter the side of squre : ";
    cin>>n;
    for(int i=1; i<=n; i++){
        for(int c=1; c<=n; c++){
            cout<<"*";
        }
        cout<<endl;
    }
}