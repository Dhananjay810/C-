#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
bool c(int i, int j, string w, vector<vector<char>>& b){
        bool flag=true;
        int n=b.size();
        int m=b[0].size();
        int g=1;
        while(flag==true){
            if(i==0 && j==0){
                if(b[i+1][j]==w[g]){
                    w[g]='1';
                    g++;
                    i=i+1;
                }
                else if(b[i][j+1]==w[g]){
                    w[g]='1';
                    g++;
                    j=j+1;
                }
                else return false;
            }
            else if(i==0 && j!=n && j!=0){
                if(b[i+1][j]==w[g]){
                    w[g]='1';
                    g++;
                    i=i+1;
                }
                else if(b[i][j+1]==w[g]){
                    w[g]='1';
                    g++;
                    j=j+1;
                }
                else if(b[i][j-1]==w[g]){
                    w[g]='1';
                    g++;
                    j=j-1;
                }
                else return false;
            }
            else if(i==0 && j==n){
                if(b[i+1][j]==w[g]){
                    w[g]='1';
                    g++;
                    i=i+1;
                }
                else return false;
            }
            else if(i==m && j==0){
                if(b[i-1][j]==w[g]){
                    w[g]='1';
                    g++;
                    i=i-1;
                }
                else if(b[i][j+1]==w[g]){
                    w[g]='1';
                    g++;
                    j=j+1;
                }
                else return false;
            }
            else if(i==m && j==n){
                if(b[i-1][j]==w[g]){
                    w[g]='1';
                    g++;
                    i=i-1;
                }
                else if(b[i][j-1]==w[g]){
                    w[g]='1';
                    g++;
                    j=j-1;
                }
                else return false;
            }
            else if(i==m && j!=n && j!=0){
                if(b[i-1][j]==w[g]){
                    w[g]='1';
                    g++;
                    i=i-1;
                }
                else if(b[i][j-1]==w[g]){
                    w[g]='1';
                    g++;
                    j=j-1;
                }
                else if(b[i][j+1]==w[g]){
                    w[g]='1';
                    g++;
                    j=j+1;
                }
                else return false;
            }
            else if(i!=m && i!=0 && j==0){
                if(b[i-1][j]==w[g]){
                    w[g]='1';
                    g++;
                    i=i-1;
                }
                else if(b[i][j+1]==w[g]){
                    w[g]='1';
                    g++;
                    j=j+1;
                }
                else if(b[i+1][j]==w[g]){
                    w[g]='1';
                    g++;
                    i=i+1;
                }
                else return false;
            }
            else if(i!=m && i!=0 && j==n){
                if(b[i-1][j]==w[g]){
                    w[g]='1';
                    g++;
                    i=i-1;
                }
                else if(b[i][j-1]==w[g]){
                    w[g]='1';
                    g++;
                    j=j-1;
                }
                else if(b[i+1][j]==w[g]){
                    w[g]='1';
                    g++;
                    i=i+1;
                }
                else return false;
            }
            else{
                if(b[i][j+1]==w[g]){
                    w[g]='1';
                    g++;
                    j=j+1;
                }
                else if(b[i][j-1]==w[g]){
                    w[g]='1';
                    g++;
                    j=j-1;
                }
                else if(b[i+1][j]==w[g]){
                    w[g]='1';
                    g++;
                    i=i+1;
                }
                else if(b[i-1][j]==w[g]){
                    w[g]='1';
                    g++;
                    i=i-1;
                }
                else return false;
            }
            if(g==w.size()) break;
        }
        return true;
    }
int main(){
    vector<vector<char>>board;
    int n;
    cin>>n;
    int m;
    cin>>m;
    for(int i=0; i<n; i++){
        for(int j=0 ;j<m; j++){
            char c;
            cin>>c;
            board[i].push_back(c);
        }
    }
    string word;
    cin>>word;
    bool flag=false;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]==word[0]){
                    if(c(i,j,word,board)==true){
                        return true;
                    }
                }
            }
        }
        return false;
}