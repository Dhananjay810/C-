#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter side : ";
    cin>>n;
    for(int i=1; i<=n; i++){
        // cout<<"*";
        for(int c=1; c<=i; c++){
            cout<<"*";


        }
        cout<<endl;
    }
}