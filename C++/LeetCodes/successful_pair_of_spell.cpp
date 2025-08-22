#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int> s={3,1,2};
    vector<int> p={8,5,8};
    int k=16;
    sort(p.begin(),p.end());
    vector<int> ans;
    for(int i=0; i<s.size(); i++){
        bool flag=false;
        for(int j=0; j<p.size(); j++){
            if(s[i]>=(float)k/p[j]){
                ans.push_back(p.size()-j);
                flag=true;
                break;
            }
        }
        if(flag==false) ans.push_back(0);
    }
    for(int i=0; i<ans.size(); i++) cout<<ans[i]<<" ";
}