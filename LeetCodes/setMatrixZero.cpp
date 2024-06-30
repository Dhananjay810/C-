#include<iostream>
#include<climits>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
void mz(vector<vector<int>>& v,int i,int j){
    int n=v.size();
    int m=v[0].size();
    for(int a=0; a<m; a++){
        if(v[i][a]!=0){
            v[i][a]=INT_MIN;
        }
        else continue;
    }
    for(int a=0; a<n; a++){
        if(v[a][j]!=0){
            v[a][j]=INT_MIN;
        }
        else continue;
    }
}
int main(){
    int m;
    cin>>m;
    int n;
    cin>>n;
    vector<vector<int>> v(m,vector<int>(n));
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>v[i][j];
        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(v[i][j]==0){
                mz(v,i,j);
            }
        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(v[i][j]==INT_MIN){
                v[i][j]=0;
            }
        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}