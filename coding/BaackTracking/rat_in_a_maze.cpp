#include<iostream>
#include<vector>
using namespace std;
vector<string> anss;

vector<vector<int>> dir={{0,-1},{-1,0},{0,1},{1,0}};
int ans=0;
bool cango(vector<vector<int>> &grid, int i, int j, int n){
    return i>=0 && j>=0 && i<n && j<n && grid[i][j]==0;
}
void f(vector<vector<int>> &grid, int row, int col, int n, string &h){
    if(row==n-1 && col==n-1){
        ans++;
        anss.push_back(h);
        return;
    }
    grid[row][col]=2;

    if(cango(grid,row,col-1,n)){
        h=h+'L';
        f(grid,row,col-1,n,h);
    }

    if(cango(grid,row-1,col,n)){
        h=h+'U';
        f(grid,row-1,col,n,h);
    }

    if(cango(grid,row,col+1,n)){
        h=h+'R';
        f(grid,row,col+1,n,h);
    }

    if(cango(grid,row+1,col,n)){
        h=h+'D';
        f(grid,row+1,col,n,h);
    }
    grid[row][col]=0;
    h.pop_back();

}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> grid(n,vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cin>>grid[i][j];
    }
    string h="";
    f(grid,0,0,n,h);
    cout<<ans;
    // for(int i=0; i<anss.size(); i++) cout<<anss[i]<<" ";

}