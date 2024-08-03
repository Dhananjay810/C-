#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    sort(v.begin(),v.end());
    int u=1;
    vector<int> r;
    for(int i=0; i<n-1; i++){
        if(v[i]==v[i+1]) u++;
        else{
            r.push_back(u);
            u=1;
        }
    }
    int mx=INT_MIN;
    r.push_back(u);
    for(int i=0; i<r.size(); i++){
        if(r[i]>mx) mx=r[i];
    }
    // for(int i=0; i<r.size(); i++) cout<<r[i]<<" ";
    // cout<<endl;
    // cout<<mx;
    if(n%2==0){
        if(mx>n/2) cout<<"NO";
        else cout<<"YES";
    }
    if(n%2!=0){
        if(mx>(n/2)+1) cout<<"NO";
        else cout<<"YES";
    }
}