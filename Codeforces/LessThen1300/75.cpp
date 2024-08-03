#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        int y;
        cin>>y;
        if(i==0) v[i]=y;
        else{
            y += v[i-1];
            v[i]=y;
        }
    }
    // for(int i=0; i<n; i++) cout<<v[i]<<" ";
    int mn=v[k-1];
    int idx=-1;
    for(int i=k; i<n; i++){
        int x=v[i]-v[i-k];
        if(x<mn){
            mn=x;
            idx=i;
        }
    }
    if(idx==-1) cout<<1;
    else cout<<idx-k+2;
}