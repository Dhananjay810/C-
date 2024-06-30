#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n ;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    vector<int> f;
    for(int i=0; i<n; i++){
        if(i==0) f.push_back(v[v.size()-1]);
        else if(i==n-1) f.push_back(v[0]);
        else f.push_back(v[i]);
    }
    for(int i=0; i<n; i++){
        cout<<f[i]<<" ";
    }
}