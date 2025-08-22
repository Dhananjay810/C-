#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter side : ";
    cin>>n;
    for(int i=1; i<=n; i++){
        for(int c=1; c<=n; c++){
            cout<<c;
        }
        cout<<endl;
    }
}