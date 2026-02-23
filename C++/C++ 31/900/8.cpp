#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        vector<int> v(n+1,1);
        for(int i=0; i<n; i++){
            if(s[i]=='<'){
                v[i+1]=v[i]+1;
            }
        }
        for(int i=n-1; i>=0; i--){
            if(s[i]=='>'){
                v[i]=max(v[i],v[i+1]+1);
            }
        }
        int maxa=-1;
        for(int i=0; i<n+1; i++) maxa=max(maxa,v[i]);
        cout<<maxa<<endl;
    }
}