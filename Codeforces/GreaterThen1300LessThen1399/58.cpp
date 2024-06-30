#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<int>> arr(n,vector<int> (2));
    for(int i=0; i<n; i++){
        for(int j=0; j<2; j++) cin>>arr[i][j];
    }
    sort(arr.begin(),arr.end());

    int r=1;
    int count=1;
    for(int i=0; i<n-1; i++){
        if(arr[i][0]==arr[i+1][0] && arr[i][1]==arr[i+1][1]) count++;
        else{
            if(count>r) r=count;
            count=1;
        }
    }
    if(count>r) r=count;
    cout<<r;

}