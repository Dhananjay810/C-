#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0; i<n; i++) cin>>v[i];
        int idxl=-1,idxh=-1;
        for(int i=0; i<n; i++){
            if(v[i]==1) idxl=i;
            if(v[i]==n) idxh=i;
        }
        if(idxl<idxh) swap(v[idxl],v[idxh]);
        for(int i=0; i<n; i++) cout<<v[i]<<" ";
        cout<<endl;
    }
}