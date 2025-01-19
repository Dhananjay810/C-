#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];

    vector<int> ans;
    int st=0;
    for(int i=2; i<n; i++){
        if(v[i]==v[i-1]+v[i-2]) continue;
        else{
            int interval=i-st;
            ans.push_back(interval);
            st=(i-1);
        }
    }
    ans.push_back(n-st);
    sort(ans.begin(), ans.end());
    cout<<ans[ans.size()-1];
}