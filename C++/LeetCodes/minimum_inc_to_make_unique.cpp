#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int> nums={3,2,1,2,1,7};
    int count=0;
    bool flag=false;
    while(flag==false){
        flag=true;
        sort(nums.begin(),nums.end());
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i]==nums[i+1]){
                count++;
                nums[i+1]++;
                flag=false;
            }
        }
    }
    cout<<count;
}