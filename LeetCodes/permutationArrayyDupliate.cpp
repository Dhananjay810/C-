#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void per(vector<int>& nums,vector<int> ans){
    if(nums.size()==0){
        for(int i=0; i<ans.size(); i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        return;
    }
    for(int i=0; i<nums.size(); i++){
        int u=nums[i];
        if(i==0){
            ans.push_back(nums[i]);
            vector<int> m;
            for(int j=0; j<nums.size(); j++){
                if(j!=i) m.push_back(nums[j]);
            }
            per(m,ans);
            ans.pop_back();
        }
        else if(u!=nums[i-1]){
            
                ans.push_back(nums[i]);
            vector<int> m;
            for(int j=0; j<nums.size(); j++){
                if(j!=i) m.push_back(nums[j]);
            }
            per(m,ans);
            ans.pop_back();
            
        }
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    cout<<endl;
    sort(v.begin(),v.end());
    vector<int> ans;
    per(v,ans);
}