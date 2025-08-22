#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int> nums={0,0,1,1,0,0,1};
    int n=nums.size();
    // int i=n-1;
    // int count=0;
    // while(i>=0){
    //     if(nums[i]==0){
    //         int a=i;
    //         if(a!=0){
    //             while(nums[a-1]!=1){
    //                 a--;
    //                 if(a==0) break;
    //             }
    //         }
    //         while(a<n){
    //             if(nums[a]==0) nums[a]=1;
    //             else nums[a]=0;
    //             a++;
    //         }
    //         count++;;
    //         i=n-1;
    //     }
    //     else i--;
    // }
    int i=0;
    int count=0;
    int u=0;
    while(i<n){
        if(u%2==0  && nums[i]==0){
            u++;
            count++;
        }
        else if(u%2!=0 && nums[i]==1){
            u++;
            count++;
        }
        i++;
    }
    cout<<count;
}