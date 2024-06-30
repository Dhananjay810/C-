#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[7];
    for(int i=0; i<7; i++){
        cin>>a[i];
    }
    int u=0;
    for(int i=0; i<1001; i++){
        for(int j=1; j<=7; j++){
            u=u+a[j-1];
            if(u>=n) {cout<<j<<" "; break;}
            else continue;
        }
        if(u>=n) break;
            else continue;
    }
    //cout<<u;
}