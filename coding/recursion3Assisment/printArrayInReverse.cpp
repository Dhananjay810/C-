#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void prirev(vector<int>& v,int idx){
    if(idx<0) return;
    cout<<v[idx]<<" ";
    prirev(v,idx-1);
}
int main(){
    vector<int> v={3,6,8,8,6,4};
    prirev(v,v.size()-1);
}