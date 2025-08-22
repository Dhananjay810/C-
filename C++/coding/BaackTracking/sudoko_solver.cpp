#include<iostream>
#include<vector>
using namespace std;
bool canPossible(vector<vector<char>> &board, int r, int c, int h){
    for(int i=0; i<9; i++){
        if(board[r][i]-'0'==h) return false;
    }
    for(int i=0; i<9; i++){
        if(board[i][c]-'0'==h) return false;
    }
    int x=(r/3)*3;
    int y=(c/3)*3;
    for(int i=x; i<x+3; i++){
        for(int j=y; j<y+3; j++){
            if(board[i][j]-'0'==h) return false;
        }
    }
    return true;
}

    bool f(vector<vector<char>> &board, int r, int c){
        if(r==9) return true;
        if(c==9) return f(board, r+1, 0);
        if(board[r][c]!='.') return f(board, r,c+1);
        for(int j=1; j<=9; j++){
            if(canPossible(board,r,c,j)){
                board[r][c]='0'+j;
                bool ree=f(board,r,c+1);
                if(ree) return true;
                board[r][c]='.';
            }
        }
        return false;
    }
int main(){
    vector<vector<char>> board{
        {'9', '.', '.', '.', '1', '3', '.', '8', '.'},
        {'4', '8', '3', '.', '5', '7', '1', '.', '6'},
        {'.', '1', '2', '.', '4', '.', '.', '3', '7'},
        {'.', '7', '.', '.', '.', '.', '.', '.', '2'},
        {'5', '.', '4', '.', '7', '.', '3', '6', '.'},
        {'.', '.', '.', '5', '.', '8', '7', '.', '1'},
        {'8', '.', '5', '7', '9', '.', '.', '1', '3'},
        {'.', '9', '1', '.', '.', '6', '.', '7', '5'},
        {'7', '.', '6', '1', '8', '5', '4', '.', '9'}
    };
    // for(int i=0; i<9; i++){
    //     for(int j=0; j<9; j++){
    //         cin>>board[i][j];
    //     }
    // }
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++) cout<<board[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl<<endl;
    bool r=f(board,0,0);
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++) cout<<board[i][j]<<" ";
        cout<<endl;
    }
}