#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter no. of which you want table :";
    cin>>n;
    int x;
    cout<<"enter till what you want table :";
    cin>>x;
    int m=1;
    while(m<=x){
        cout<<n*m<<"   ";
        m++;
    }

}