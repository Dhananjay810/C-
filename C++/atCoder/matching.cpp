#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<int>> c(n+1,vector<int>(n+1));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++) cin>>c[i][j];
    }
}