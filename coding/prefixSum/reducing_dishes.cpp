#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int> satisfaction={2,-2,-3,1};
    int n=satisfaction.size();
    sort(satisfaction.begin(),satisfaction.end());
    vector<int> suf(n);
    suf[n-1]=satisfaction[n-1];
    int idx=n;
    for(int i=n-2; i>=0; i--){
        suf[i]=suf[i+1]+satisfaction[i];
    }
    for(int i=0; i<n; i++){
        if(suf[i]>0){
            idx=i;
            break;
        }
    }
    int u=1;
    int count=0;
    for(int i=idx; i<n; i++){
        count=count+satisfaction[i]*u;
        u++;
    }
    cout<<count;
}