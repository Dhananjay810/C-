#include <bits/stdc++.h>
using namespace std;

bool is(vector<int> &v){
    for(int i=1; i<v.size(); i++){
        if(v[i]!=v[0]) return false;
    }
    return true;
}

int f(int i, vector<int> &v){
    int n=v.size();
    if(i==n) return 0;
    int a=f(i+1,v);
    if(v[i]%2==0) v[i]=v[i]/2;
    int b=1+f(i+1,v);
    v[i]=v[i]*2;
    v[i]=v[i]+1;
    int c=1+f(i+1,v);
    v[i]=v[i]-1;
    return min(a,min(b,c));
}

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0; i<n; i++) cin>>v[i];
        if(is(v)==true){
            cout<<0<<"\n";
        }
        else{
            cout<<f(0,v)<<"\n";
        }
    }
}
