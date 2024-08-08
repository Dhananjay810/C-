#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    int k=0;
    vector<vector<int>> v(n,vector<int>(2));
    for(int i=0; i<n; i++){
        for(int j=0; j<2; j++){
            cin>>v[i][j];
        }
    }
    for(int i=0; i<n; i++){
        int u=v[i][1];
        for(int j=0; j<n; j++){
            if(i!=j && u==v[j][0]){
                k++;
                v[j][0]=-1;
            }
        }
    }
    cout<<n-k;
}