#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int main(){
    vector<int> nums={1,1,1,1,1,1,1,1};
    int n=nums.size();
    int target=11;
    int i=0;
    int j=0;
    int length=-1;
    int minlength=INT_MAX;
    int sum=0;
    while(j<n){
        sum=sum+nums[j];
        while(sum>=target){
            length=j-i+1;
            minlength=min(minlength,length);
            sum=sum-nums[i];
            i++;
        }
        j++;
    }
    if(minlength>n){
        cout<<"0";
        return 0;
    }
    cout<<minlength;
}