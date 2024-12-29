#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int pro(vector<int> &arr){
    sort(arr.begin(), arr.end());
    if(arr[0]>=0) return arr[0];
    int po=0;
    int ne=0;
    for(int i=0; i<arr.size(); i++){
        if(arr[i]<0) ne++;
        else if(arr[i]>0) po++;
    }
    if(ne%2==0) ne=ne-1;
    int ans=1;
    for(int i=0; i<ne; i++){
        ans=ans*arr[i]; 
    }
    for(int j=0; j<po; j++){
        ans=ans*arr[arr.size()-1-j];
    }
    return ans;
}
int main(){
    vector<int> arr={2,3,2,4,0,8,3};
    cout<<pro(arr)<<endl;
}