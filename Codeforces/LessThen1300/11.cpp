#include<iostream>
using namespace std;
int main(){
    int n,m;
    cin>>n;
    cin>>m;
    for(int i=n+1; i<=60; i++){
        int t=0;
        for(int j=2; j<i; j++){
            if(i%j!=0){
                t++;
            }
            else break;
        }
        if(t==i-2){
            if(i==m) cout<<"YES";
            else cout<<"NO";
            //cout<<i;
            break;
        }
        else continue;
    }
}