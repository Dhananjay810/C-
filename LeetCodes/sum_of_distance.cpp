#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int> v={0,5,3,8,5,5,7,7,9,9,6,6,5,2,4,2,4,5,8,7,5,2,6,9,7,4,1,2,5,8,2,1,9,2,2,1,4,5,2,2,3,6,99,7,7,4,1,2,5,2,4};
    vector<long long> ans(v.size());
    for(int i=0; i<v.size(); i++){
        int c=0;
        for(int j=0; j<v.size(); j++){
            if(i!=j && v[i]==v[j]){
                c=c+abs(i-j);
            }
        }
        ans[i]=c;
    }
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
}