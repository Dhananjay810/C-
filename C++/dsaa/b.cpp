#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<int>> v(n,vector<int>(4));
    for(int i=0;i<n;i++){
        for(int j=0; j<4; j++) cin>>v[i][j];
    }
    for(int i=0; i<n; i++){
        int win=0;
        if(v[i][0]>v[i][2]){
            if(v[i][1]>v[i][3]) win++;
        }
        if(v[i][0]>v[i][3]){
            if(v[i][1]>v[i][2]) win++;
        }
        if(v[i][1]>v[i][2]){
            if(v[i][0]>v[i][3]) win++;
        }
        if(v[i][1]>v[i][3]){
            if(v[i][0]>v[i][2]) win++;
        }
        cout<<win<<endl;
    }
}