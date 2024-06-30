#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void dup(vector<int>& nums, vector<int> v, vector<vector<int>>& s, int idx, bool flag){
    if(idx==nums.size()){
        s.push_back(v);
        return;
    }
    int d=nums[idx];
    if(idx==nums.size()-1){
        dup(nums,v,s,idx+1,true);
        if(flag==true){
            v.push_back(nums[idx]);
            dup(nums,v,s,idx+1,true);
        }
        return;
    }
    int g=nums[idx+1];
    if(g==d){
        dup(nums,v,s,idx+1,false);
        if(flag==true){
            v.push_back(nums[idx]);
            dup(nums,v,s,idx+1,true);
        }
    }
    else{
        dup(nums,v,s,idx+1,true);
        if(flag==true){
            v.push_back(nums[idx]);
            dup(nums,v,s,idx+1,true);
        }
    }
}
int main(){
    vector<int> nums={1,2,2};
    sort(nums.begin(),nums.end());
    vector<int> v;
    vector<vector<int>> s;
    dup(nums,v,s,0,true);
    for(int i=0; i<s.size(); i++){
        for(int j=0; j<s[i].size(); j++){
            cout<<s[i][j]<<" ";
        }
        cout<<endl;
    }
}