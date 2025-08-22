#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int search(vector<int>& v,int f,int idx){
    if(idx==v.size()) return -1;
    if(v[idx]==f) return idx;
    return search(v,f,idx+1);
}
int main(){
    vector<int> v={3,6,8,8,6,4};
    int f=8;
    cout<<search(v,f,0);
}