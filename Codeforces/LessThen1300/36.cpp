#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int e=999999;
    if(e<0) e=e*(-1);
    int u=0,v=0;
    for(int i=0; i<n; i++){
        int r=0;
        if(i<n-1){
            r=a[i]-a[i+1];
            if(r<0) r=r*(-1);
            if(r<e){
                e=r;
                u=i;
                v=i+1;
            }
        }
        else{
            r=a[i]-a[0];
            if(r<0) r=r*(-1);
            if(r<e){
                e=r;
                u=i;
                v=0;
            }
        }
        //cout<<r<<" ";
    }
    cout<<u+1<<" "<<v+1;
}