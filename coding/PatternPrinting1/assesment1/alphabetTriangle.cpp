#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter side of triangle : ";
    cin>>n;
    for(int i=65; i<65+n; i++){
        for(int j=65; j<=i; j++){
            char a=(char)j;
            cout<<a;
        }
        cout<<endl;
    }
}