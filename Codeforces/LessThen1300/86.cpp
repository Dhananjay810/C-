#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v(n,vector<int>(2));
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++) cin>>v[i][j];
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    int u=1;
    int h=1;
    int val=0;
    for(int i=0; i<n; i++){
        if(u==m){
            val=v[i][0];
            break;
        }
        else{
            u++;
        }
    }
    // int g=0;
    // for(int i=0; i<n; i++){
    //     if(v[i][0]==val) g++;
    // }
    // cout<<g;
    for(int i=0; i<n; i++){
        for(int j=0; j<2; j++) cout<<v[i][0]<<" ";
        cout<<endl;
    }
    cout<<endl;
    cout<<val;
}