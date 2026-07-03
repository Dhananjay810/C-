#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        priority_queue<pair<int,int>> q;
        for(int i=0; i<n; i++){
            cin>>v[i];
            q.push({v[i],i});
        }
        // while(q.size()>0){
        //     cout<<q.top().first<<" "<<q.top().second<<endl;
        //     q.pop();
        // }
        // break;
        int ans=0;
        int y=n-1;
        int idx=n-1;
        while(y>0){
            auto x=q.top();
            // cout<<x.second<<" "<<y<<endl;
            q.pop();
            if(x.second>idx) continue;
            idx=min(idx,x.second);

            y=x.second;
            // cout<<y<<endl;
            ans++;
        }
        cout<<ans<<endl;
    }
}