#include<iostream>
using namespace std;
int main(){
    int n;
    int m;
    cin>>n>>m;
    int i=1;
    while(m>=i){
        if(i<n){
            m=m-i;
            i++;
        }
        else if(i==n){
            m=m-i;
            i=1;
        }
    }
    cout<<m;
}