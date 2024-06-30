#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void subArray(vector<int>& nums,vector<int> v,int size,int idx){
    if(idx==size){
        for(int i=0; i<v.size(); i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;

        return;
    }
    if(v.size()==0 || v[v.size()-1]!=nums[idx]){
        subArray(nums,v,size,idx+1);
    }
    
    if(v.size()==0 || v[v.size()-1]==nums[idx-1]){
    v.push_back(nums[idx]);
    subArray(nums,v,size,idx+1);}
}
int main(){
    // MUST HAVE  UNIQUE ELLEMENTS
    vector<int> nums={1,2,1};
    sort(nums.begin(),nums.end());
    int n=nums.size();
    vector<int> v;
    subArray(nums,v,n,0);
}