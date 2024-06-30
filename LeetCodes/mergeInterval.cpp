#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int m;
    cin>>m;
    int a[m][2];
    for(int i=0; i<m; i++){
        for(int j=0; j<2; j++){
            cin>>a[i][j];
        }
    }
    vector<vector<int>> v;
    for(int i=0; i<m; i++){
        if(a[i][1]>=a[i+1][0] && i<m-1){
            v.push_back({a[i][0],a[i+1][1]});
            i++;
        }
        else{
            v.push_back({a[i][0],a[i][1]});
        }
    }
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<2; j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}