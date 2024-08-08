#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void shower(vector<vector<int>> &v,vector<string> k,int s){
    int n=v.size();
    if((v[0][0]-0)>=s){
        k.push_back("YES");
        return;
    }
    else{
        for(int i=0; i<n-1; i++){
            if((v[i+1][0]-v[i][1])>=s){
                k.push_back("YES");
                return;
            }
        }
        if((10-v[n-1][1])>=s) k.push_back("YES");
        else k.push_back("N0");
    }
}
int main(){
    int t;
    cin>>t;
    int n,s,m;
    cin>>n>>s>>m;
    vector<string> k(n);
    for(int i=0; i<t; i++){
        vector<vector<int>> v(n,vector<int>(2));
        for(int j=0; j<n; j++){
            for(int k=0; k<2; k++) cin>>v[j][k];
        }
        shower(v,k,s);
    }
    for(int i=0; i<k.size(); i++) cout<<k[i]<<endl;
}