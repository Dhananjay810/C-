#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void sum(vector<int>& nums,vector<int>& v,vector<int> ans,int idx,bool flag){
    if(idx==nums.size()){
        int u=0;
        for(int i=0; i<ans.size(); i++){
            u=u+ans[i];
            }
            v.push_back(u);
        return;
    }
    int h=nums[idx];
    if(idx==nums.size()-1){
        sum(nums,v,ans,idx+1,true);
        if(flag==true){
            ans.push_back(nums[idx]);
            sum(nums,v,ans,idx+1,true);
        }
        return;
    }
    int g=nums[idx+1];
    if(g==h){
        sum(nums,v,ans,idx+1,false);
        if(flag==true){
            ans.push_back(nums[idx]);
            sum(nums,v,ans,idx+1,true);
        }
    }
    else{
        sum(nums,v,ans,idx+1,true);
        if(flag==true){
            ans.push_back(nums[idx]);
            sum(nums,v,ans,idx+1,true);
        }
    }
}
int main(){
    vector<int> nums={1,2,3,5};
    vector<int> v;
    vector<int>ans;
    sum(nums,v,ans,0,true);
    sort(v.begin(),v.end());
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
}