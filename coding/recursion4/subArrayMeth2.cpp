#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
void subArray(vector<int>& nums,vector<int> v,int size,int idx,long long &k){
    if(idx==size){
        long long h=1;
        for(int i=0; i<v.size(); i++){
            h=h*v[i];
            cout<<v[i]<<" ";
        }
        if(v.size()!=0 && h>k) k=h;
        cout<<endl;

        return;
    }
    if(v.size()==0 || v[v.size()-1]!=nums[idx]){
        subArray(nums,v,size,idx+1,k);
    }
    
    if(v.size()==0 || v[v.size()-1]==nums[idx-1]){
    v.push_back(nums[idx]);
    subArray(nums,v,size,idx+1,k);}
}
int main(){
    // MUST HAVE  UNIQUE ELLEMENTS
    vector<int> nums={2,-2,-2,0,-2,2,2};
    //sort(nums.begin(),nums.end());
    int n=nums.size();
    vector<int> v;
    long long int k=INT_MIN;
    subArray(nums,v,n,0,k);
    cout<<endl<<k;
}