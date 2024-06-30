#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int min(vector<int>& v,int mini,int idx){
    if(idx==v.size()){
        return mini;
    }
    mini=min(v[idx],mini);
    return min(v,mini,idx+1);
}
int main(){
    vector<int> v={3,6,8,8,6,4};
    cout<<min(v,1000,0);
}