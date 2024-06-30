#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<vector<int>> v={
        {1,3},
        {2,6},
        {1,5}
    };
    int x=5;
    vector<int> q={10,11};
    for(int i=0; i<v.size(); i++){
        reverse(v[i].begin(),v[i].end());
    }
    sort(v.begin(),v.end());
    cout<<endl;
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v[i].size(); j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}