#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void store(int arr[],int n, int idx, vector<int> v, vector<vector<int>>& s){
    if(idx==n){
        s.push_back(v);
        return;
    }
    store(arr,n,idx+1,v,s);
    v.push_back(arr[idx]);
    store(arr,n,idx+1,v,s);
}
int main(){
    int arr[]={1,3,4};
    vector<int>v;
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<vector<int>> s;
    store(arr,n,0,v,s);
    for(int i=0; i<s.size(); i++){
        for(int j=0; j<s[i].size(); j++){
            cout<<s[i][j]<<" ";
        }
        cout<<endl;
    }
}