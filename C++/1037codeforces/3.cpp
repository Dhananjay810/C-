#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> v(n);
        for(int i=0; i<n; i++) cin>>v[i];
        priority_queue<int,vector<int>, greater<int>> pq;
        for(int i=0; i<n; i++){
            if(v[i]>v[k-1]){
                // cout<<v[i]<<" ";
                pq.push(v[i]);
            }
        }
        int currwate=0;
        int currheight=v[k-1];
        while(pq.size()>0){
            int u=pq.top();
            pq.pop();
            int diff=u-currheight;
            int tim=currheight-currwate;
            if(tim<diff) break;
            else{
                currwate+=diff;
                currheight=u;
            } 
        }
        if(pq.size()==0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}