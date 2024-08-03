#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<int>> v(n,vector<int>(2));
    for(int i=0; i<n; i++){
        for(int j=0; j<2; j++) cin>>v[i][j];
    }
    int lo=0,ri=0;
    for(int i=0; i<n; i++) lo += v[i][0];
    for(int i=0; i<n; i++) ri += v[i][1];
    int count=1;
    bool flag=false;
    if(lo%2==0 && ri%2==0){
        cout<<"0";
        return 0;
    }
    else if(lo%2!=0 && ri%2!=0){
        for(int i=0; i<n; i++){
            if((v[i][0]%2!=0 && v[i][1]%2==0) || (v[i][0]%2==0 && v[i][1]%2!=0)){
                flag=true;
                cout<<"1";
                break;
            }
        }
        if(flag==false) cout<<"-1";

    }
    else cout<<"-1";
}