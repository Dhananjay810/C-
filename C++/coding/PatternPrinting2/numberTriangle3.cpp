#include<iostream>
using namespace std;
int main(){
    int t;
    cout<<"enter side : ";
    cin>>t;

    for(int i=1; i<=t; i++){
        for(int j=i; j>=1; j--){
            cout<<j;
        }
        cout<<endl;
    }
}