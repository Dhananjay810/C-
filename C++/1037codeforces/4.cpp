#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int f(int idx,int k, vector<vector<int>> &v){
    if(idx>v.size()) return k;
    if(k<v[idx][0] || k>v[idx][1]) return k;
    return max(f(idx+1,v[idx][2],v),f(idx+1,k,v));
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<vector<int>> v(n,vector<int>(3));
        for(int i=0; i<n; i++){
            for(int j=0; j<3; j++) cin>>v[i][j];
        }
        sort(v.begin(),v.end());
        for(int i=0; i<n; i++){
            cout<<v[i][0]<<" "<<v[i][1]<<" "<<v[i][2]<<endl;
        }
        cout<<f(0,k,v)<<endl;
    }
}