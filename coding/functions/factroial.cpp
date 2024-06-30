#include<iostream>
using namespace std;
float fact(int n){
    float z=1;
    for(int i=2; i<=n; i++){
        z=z*i;
    }
    return z;
}
int main(){
    float n;
    cout<<"enter no. till fact. calculated : ";
    cin>>n;
    float h=fact(n);
    cout<<h;
}