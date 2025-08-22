#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter no. : ";
    cin>>n;
    int y=1;
    for(int i=1; i<=n; i++){
        y=y*i;
        cout<<i<<" factorial is-->"<<y<<endl;

    }
    
}