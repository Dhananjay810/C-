#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
int main(){
    string s="YYYY";
    vector<int> pre(s.size()+1);
    vector<int> suf(s.size()+1);
    pre[0]=0;
    for(int i=1; i<=s.size(); i++){
        if(s[i-1]=='N'){
            pre[i]=pre[i-1]+1;
        }
        else pre[i]=pre[i-1]+0;
    }

    suf[suf.size()-1]=0;
    for(int i=s.size()-1; i>=0; i--){
        if(s[i]=='Y') suf[i]=suf[i+1]+1;
        else suf[i]=suf[i+1]+0;
    }
    for(int i=0; i<pre.size(); i++){
        pre[i]=pre[i]+suf[i];
    }
    int min=INT_MAX;
    int idx=-1;
    for(int i=0; i<pre.size(); i++){
        if(pre[i]<min){
            min=pre[i];
            idx=i;
        }
    }
    cout<<idx;
}