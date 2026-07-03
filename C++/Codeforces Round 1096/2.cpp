#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int l=0;
        int r=0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='(') l++;
            else r++;
        }
        if(l==r) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}