#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int> nums={1,2,3,4};
    int n=nums.size();
    vector<int> ans;
    ans.push_back(nums[0]);
    for(int i=1; i<n; i++){
        int sum=nums[i]+ans[ans.size()-1];
        ans.push_back(sum);
    }
    for(int i=0; i<n; i++) cout<<ans[i]<<" ";
}