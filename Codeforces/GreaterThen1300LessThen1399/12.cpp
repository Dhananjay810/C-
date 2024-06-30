#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int>f(n);
    vector<int>t(n);
    for(int i=0; i<n; i++){
        for(int j=0; j<2; j++){
            if(j==0) cin>>f[i];
            else cin>>t[i];
        }
    }
    vector<int>max;
    for(int i=0; i<n; i++){
        if(t[i]>k){
            int u=0; 
            u=f[i]-(t[i]-k);
            max.push_back(u);
        }
        else max.push_back(f[i]);
    }
    sort(max.begin(),max.end());
    cout<<max[max.size()-1];
}