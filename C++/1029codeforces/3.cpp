#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0; i<n; i++) cin>>v[i];
        unordered_map<int,priority_queue<int,vector<int>,greater<int>>> m;
        for(int i=0; i<n; i++){
            m[v[i]].push(i);
        }
        int i=0;
        int j=1;
        bool flag1=false;
        int ans=1;
        m[v[i]].pop();
        while(i<n && j<n){
            vector<int> a(v.begin()+i,v.begin()+j);
            int u=j;
            for(int w=0; w<a.size(); w++){
                flag1=false;
                if(m.find(a[w])!=m.end()){
                    int idx=m[a[w]].top();
                    m[a[w]].pop();
                    u=max(u,idx);
                    if(m[a[w]].size()==0) m.erase(a[w]);
                    flag1=true;
                }
                else break;
            }
            if(flag1==false){
                break;
            }
            i=j;
            j=u;
            ans++;
        }
        cout<<ans<<endl;
    }
}