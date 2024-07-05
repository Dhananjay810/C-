#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>> v(n,vector<char>(m));
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        for(int j=0; j<m; j++){
            char ch=s[j];
            if(ch=='.'){
                if((i+j)%2==0) v[i][j]='B';
                else v[i][j]='W';
            }
            else v[i][j]=ch;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<v[i][j];
        }
        cout<<endl;
    }
} 