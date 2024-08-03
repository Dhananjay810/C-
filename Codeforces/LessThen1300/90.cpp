#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    long long n;
    cin>>n;
    vector<long long> v(n);
    vector<long long> s(n);
    for(int i=0;i<n;i++) cin>>v[i];
    for(int i=0; i<n; i++) s[i]=v[i];
    sort(s.begin(),s.end());
    for(int i=1; i<n; i++){
        v[i] += v[i-1];
    }
    for(int i=1; i<n; i++){
        s[i] += s[i-1];
    }
    long long m;
    cin>>m;
    vector<vector<long long>> k(m,vector<long long>(3));
    for(int i=0; i<m; i++){
        for(int j=0; j<3; j++) cin>>k[i][j];
    }
    for(int i=0; i<m; i++){
        long long w=k[i][0];
        if(w==1){
            if(k[i][1]==1) cout<<v[k[i][2]-1];
            else cout<<(v[k[i][2]-1]-v[k[i][1]-2]);
        }
        if(w==2){
            if(k[i][1]==1) cout<<s[k[i][2]-1];
            else cout<<(s[k[i][2]-1]-s[k[i][1]-2]);
        }
        cout<<endl;
    }
}