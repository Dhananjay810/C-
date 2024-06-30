#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void subArray(vector<int>& nums,vector<int> v,int size,int idx,vector<int>& sum,int k){
    if(v.size()==3){
        int u=0;
        for(int i=0; i<v.size(); i++){
            cout<<v[i]<<" ";
           // u=u+v[i];
        }
        //if(u%k==0) sum[0]++;
        cout<<endl;

        return;
    }
    if(v.size()==0 || v[v.size()-1]!=nums[idx]){
        subArray(nums,v,size,idx+1,sum,k);
    }
        
    
    if(v.size()==0 || v[v.size()-1]==nums[idx-1]){
    v.push_back(nums[idx]);
    subArray(nums,v,size,idx+1,sum,k);}
}
int main(){
    // MUST HAVE  UNIQUE ELLEMENTS
    vector<int> nums={0,0,0};
    int k=5;
    int n=nums.size();
    sort(nums.begin(),nums.end());
    vector<int> v;
    vector<int> sum={0};
    subArray(nums,v,n,0,sum,k);
    //cout<<sum[0]-1;
}