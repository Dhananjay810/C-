#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define ll long long int
using namespace std;
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> v(n);
        for(int i=0; i<n; i++) cin>>v[i];
        vector<ll> suf(n);
        suf[n-1]=v[n-1];
        for(int i=n-2; i>=0; i--){
            suf[i]=suf[i+1]+v[i];
        }
        priority_queue<ll> pq;
        vector<ll> maxa(n);
        for(int i=0; i<n; i++){
            pq.push(v[i]);
            maxa[i]=pq.top();
        }
        cout<<maxa[n-1]<<" ";
        for(int i=n-2; i>=0; i--){
            ll mxx=maxa[i];
            ll y=suf[i+1];
            cout<<mxx+y<<" ";
        }
        cout<<endl;
    }
}