#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int maxa(vector<int>& v, int idx){
    if(idx==v.size()) return INT_MIN;
    return max(v[idx],maxa(v,idx+1));
}
int main(){
    vector<int>v={4,6,3,2,7,91,0,5};
    cout<<maxa(v,0);

}