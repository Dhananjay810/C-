#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int> arr={1,0,3,4};
    vector<int> pre(arr.size());
    vector<int> suf(arr.size());
    vector<int> ans(arr.size());
    pre[0]=1;
    for(int i=0; i<arr.size()-1; i++){
        pre[i+1]=pre[i]*arr[i];
    }
    suf[arr.size()-1]=1;
    for(int i=0; i<arr.size()-1; i++){
        suf[arr.size()-2-i]=suf[arr.size()-1-i]*arr[arr.size()-1-i];
    }
    for(int i=0; i<arr.size(); i++){
        ans[i]=pre[i]*suf[i];
    }
    for(int i=0; i<pre.size(); i++){
        cout<<ans[i]<<" ";
    }
}