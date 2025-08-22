#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int sum(vector<int>& v,int ans,int idx){
    if(idx==v.size()) return ans;
    return sum(v,ans+v[idx],idx+1);
}
int main(){
    vector<int> v={3,6,8,8,6,4};
    cout<<sum(v,0,0);
}