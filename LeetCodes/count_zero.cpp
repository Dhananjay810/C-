#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
int main(){
    int m=3;
    vector<vector<int>> logs={
        {1,3},
        {2,6},
        {1,5}
    };

    int x=5;
    vector<int> queries={10,11};
    int n=logs.size();
    vector<int> v;
    vector<int> l(n);
    for(int i=0; i<n; i++) l[i]=logs[i][1];
    sort(l.begin(),l.end());
    v.push_back(l[0]);
    for(int i=1; i<n; i++){
        if(l[i]!=l[i-1]) v.push_back(l[i]);
    }
   // for(int i=0; i<v.size(); i++) cout<<v[i]<<" ";
    cout<<endl;
    sort(queries.begin(),queries.end());
    int i=0,j=0,count=0;
    int u=0;
    int st=queries[u]-x,en=queries[u];
    vector<int> ans(queries.size());
    while((i<n || j<n) && u<queries.size()){

        if(j==n){
            if(v[i]<st) i++;
            else {
            ans[u]=i;
           // cout<<i<<" "<<j<<endl;
            u++;
           // cout<<u<<endl;
            st=queries[u]-x,en=queries[u];
            }
        }
        else {
        if(v[i]<st){
            if(i!=j) i++;
            else{
                i++;
                j++;
            }
        }
        else if(v[j]>en){
            int b=n-j;
           // cout<<i<<" "<<j<<endl;
            ans[u]=i+b;
            u++;
            //cout<<u<<endl;
            st=queries[u]-x,en=queries[u];
        }
        else j++;
        }
    }
    for(int c=0; c<ans.size(); c++){
        cout<<ans[c]<<" ";
    }
}