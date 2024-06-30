#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int arr[]={1,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    int i=0;
    while(i<n){
        int idx=arr[i]-1;
        if(arr[i]==arr[idx] || arr[i]==idx) i++;
        else swap(arr[i],arr[idx]);
    }
    vector<int>ans;
    for(int i=0; i<n; i++){
        if(arr[i]!=i+1) ans.push_back(i+1);
    }
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
}