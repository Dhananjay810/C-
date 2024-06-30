#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void comb(vector<int>& nums, vector<int> v,int target,int idx){
    int n=nums.size();
    if(target==0){
        for(int i=0; i<v.size(); i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
        return;
    }
    if(target<0) return;
    for(int i=idx; i<n; i++){
        v.push_back(nums[i]);
        comb(nums,v,target-nums[i],i);
        v.pop_back();
    }
}
int main(){
    vector<int> nums={1,2,3};
    int target=3;
    vector<int> v;
    comb(nums,v,target,0);
}