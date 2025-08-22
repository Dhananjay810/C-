#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
bool g(vector<int> &a, vector<int> &b){
    unordered_map<int,int> aa,bb;
    for(int i=0; i<a.size(); i++){
        aa[a[i]]++;
        bb[b[i]]++;
    }
    for(auto x : aa){
        if(bb.find(x.first)==bb.end()) return false;
        if(aa[x.first]==bb[x.first]) return true;
    }
    return false;
}
bool f(vector<int> a,vector<int> b, int k, int n, int i){
    if(i==n){
        if(g(a,b)) return true;
        return false;
    }
    int aa=a[i]+k;
    int bb=abs(a[i]-k);
    a[i]=aa;
    bool f1=f(a,b,k,n,i+1);
    a[i]=bb;
    bool f2=f(a,b,k,n,i+1);
    if(f1 || f2) return true;
    return false;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> a(n),b(n);
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        for(int i=0; i<n; i++){
            cin>>b[i];
        }
        if(f(a,b,k,n,0)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}