#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool f(vector<int> &a, int idx, int ans, int s){
    if(idx==a.size()-1){
        if(ans==s) return true;
        return false;
    }
    if(idx>0){
        ans+=a[idx];
        bool d=f(a,idx-1,ans,s);
        if(d==true) return true;
        ans-=a[idx];
    }
    ans+=a[idx];
    bool d=f(a,idx+1,ans,s);
    ans-=a[idx];
    if(d==true) return true;
    return false;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,s;
        cin>>n>>s;
        vector<int> a(n);
        for(int i=0; i<n; i++) cin>>a[i];
        sort(a.begin(),a.end());
        reverse(a.begin(),a.end());
        if(f(a,0,0,s)){
            cout<<"-1";
        }
        else{
            for(int i=0; i<n; i++) cout<<a[i]<<" ";
        }
        cout<<endl;
    }
}