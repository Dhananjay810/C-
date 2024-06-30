#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<int>>v(n,vector<int>(2));
    vector<int>k;
    for(int i=0; i<n; i++){
        for(int j=0; j<2; j++){
            cin>>v[i][j];
            if(j==1) k.push_back(v[i][j]);
        }
    }
    bool flag=true;
    sort(v.begin(),v.end());
    sort(k.begin(),k.end());
    reverse(k.begin(),k.end());
    for(int i=0; i<n; i++){
        if(v[i][1]==k[i]) continue;
        else{
            flag=false;
            cout<<"Poor Alex";
            break;
        }
    }
    if(flag==true) cout<<"Happy Alex";
}