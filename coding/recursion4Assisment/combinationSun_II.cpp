#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void dup(vector<int>& nums,vector<int> ans,vector<vector<int>>& v,int idx,int tar){
    if(tar==0){
        v.push_back(ans);
        return;
    }
    if(tar<0) return;
    for(int i=idx; i<nums.size(); i++){
        if(i>idx && nums[i]==nums[i+1]) continue;
        if(nums[i]>tar) break;
        ans.push_back(nums[i]);
        dup(nums,ans,v,i+1,tar-nums[i]);;
        ans.pop_back();
    }
}
int main(){
    vector<int> nums={1,5,11,5};
    int tar=11;
    sort(nums.begin(),nums.end());
    vector<int> ans;
    vector<vector<int>> v;
    dup(nums,ans,v,0,tar);
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v[i].size(); j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}