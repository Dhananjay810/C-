#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<vector<char>> ans;

bool isPossible(int row, int col, int n){
    for(int i=row-1; i>=0; i--){
        if(ans[i][col]=='Q') return false;
    }
    for(int i=row-1, j=col-1; i>=0 && j>=0; i--,j--){
        if(ans[i][j]=='Q') return false;
    }
    for(int i=row-1, j=col+1; i>=0 && j<n; i--, j++){
        if(ans[i][j]=='Q') return false;
    }
    return true;
}

void f(int row, int n){
    if(row==n){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++) cout<<ans[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;
        return;
    }

    for(int col=0; col<n; col++){
        if(isPossible(row, col, n)){
            ans[row][col]='Q';
            f(row+1,n);
            ans[row][col]='.';
        }
    }
}

vector<vector<string>> NQueens(int n) {
        ans.resize(n,vector<char>(n,'.'));
        f(0,n);
        return {};
}
int mian(){
    NQueens(4);
    return 0;
}