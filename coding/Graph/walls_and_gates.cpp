#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
vector<vector<int>> wallsAndGates(vector<vector<int>> &a, int n, int m) {
    queue<pair<pair<int,int>,int>> q;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j]==0)q.push({{i,j},1});
        }
    }
    vector<vector<int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
    while(q.size()>0){
        int aa=q.front().first.first;
        int b=q.front().first.second;
        int l=q.front().second;
        q.pop();
        for(int d=0; d<4; d++){
            int newr=aa+dir[d][0];
            int newc=b+dir[d][1];
            if(newr<0 || newc<0 || newr>=n || newc>=m) continue;
            if(a[newr][newc]!=INT_MAX) continue;
            q.push({{newr,newc},l+1});
            a[newr][newc]=l;
        }
    }
    return a;
}
int main(){
    vector<vector<int>> a={{INT_MAX,-1,0,INT_MAX},{INT_MAX,INT_MAX,INT_MAX,-1},{INT_MAX,-1,INT_MAX,-1},{0,-1,INT_MAX,INT_MAX}};
    vector<vector<int>> ans=wallsAndGates(a,4,4);
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}