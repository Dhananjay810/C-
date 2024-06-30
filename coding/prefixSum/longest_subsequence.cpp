#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int> v={4,5,2,1};
    vector<int> q={3,10,21};
    sort(v.begin(),v.end());
    int n=v.size();
    for(int i=1; i<n; i++){
        v[i]=v[i]+v[i-1];
    }
    vector<int> ans;
    for(int i=0; i<q.size(); i++){
        int len=0;
        for(int j=0; j<n; j++){
            if(v[j]>q[i]) break;
            len++;
        }
        ans.push_back(len);
    }
    for(int i=0; i<ans.size(); i++) cout<<ans[i]<<" ";
}