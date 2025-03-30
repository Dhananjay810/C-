#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int minimumKnightMoves(int x, int y) {
    vector<vector<int>> dir={{1,2},{2,1},{-2,1},{-1,2},{-2,-1},{-1,-2},{1,-2},{2,-1}};
    int u=1;
    queue<pair<pair<int,int>,int>> q;
    for(int i=0; i<8; i++){
        int a=0,b=0;
        q.push({{a+dir[i][0],b+dir[i][1]},1});
    }
    while(q.size()>0){
        int i=q.front().first.first;
        int j=q.front().first.second;
        int l=q.front().second;
        if(i==x && j==y) return l;
        q.pop();
        for(int d=0; d<8; d++){
            int newr=i+dir[d][0];
            int newc=j+dir[d][1];
            q.push({{newr,newc},l+1});
        }
    }
}
int main(){
    int x,y;
    cin>>x>>y;
    cout<<minimumKnightMoves(x,y);
}