#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void tri(vector<int>& nums){
    if(nums.size()==0) return;
    for(int i=0; i<nums.size(); i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    vector<int> ans;
    for(int i=0; i<nums.size()-1; i++){
        ans.push_back(nums[i]+nums[i+1]);
    }
    tri(ans);
}
int main(){
    vector<int> nums={5,4,3,2,1};
    tri(nums);
}