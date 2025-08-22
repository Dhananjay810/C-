#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int> arr1={28,6,22,8,44,17};
    vector<int> arr2={22,28,8,6};
    vector<int> ans;
    for(int i=0; i<arr2.size(); i++){
        for(int j=0; j<arr1.size(); j++){
            if(arr2[i]==arr1[j]){
                ans.push_back(arr1[j]);
                arr1[j]=2000;
            }
        }
    }
    int n=arr1.size()-ans.size();
    if(n!=0){
    sort(arr1.begin(),arr1.end());
    for(int i=0; i<n; i++){
        ans.push_back(arr1[i]);
    }}
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
}