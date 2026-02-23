#include<iostream>
#include<vector>
using namespace std;
int main(){
    long long n;
    cin>>n;
    if(n<4){
        if(n==1){
            cout<<"1";
        }
        else cout<<"NO SOLUTION";
        return 0;
    }
    vector<long long> ans;
    int i=2;
    while(i<=n){
        ans.push_back(i);
        i=i+2;
    }
    i=1;
    while(i<=n){
        ans.push_back(i);
        i=i+2;
    }
    for(int i=0; i<ans.size(); i++) cout<<ans[i]<<" ";
}