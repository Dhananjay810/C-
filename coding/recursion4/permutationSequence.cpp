#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string st(string h,string ans,int k){
    int n=h.size();
    if(n==1){
        ans=ans+h;;
        return ans;
    }
    int fact=1;
    for(int i=2; i<=n-1; i++){
        fact=fact*i;
    }
    int idx=k/fact;
    if(k%fact==0) idx=idx-1;
    char ch=h[idx];
    string l=h.substr(0,idx);
    string r=h.substr(idx+1);
    int q=1;
    if(k%fact==0) q=fact;
    else q=k%fact;
    return st(l+r,ans+ch,q);
}
int main(){
    int n,k;
    cin>>n>>k;
    string h="";
    for(int i=1; i<=n; i++){
        h=h+to_string(i);
    }
    cout<<st(h,"",k);
}