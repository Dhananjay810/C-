#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0; i<n; i++) cin>>v[i];
        int maxa=INT_MIN;
        for(int i=0; i<n-1; i++) maxa=max(maxa,(v[n-1]-v[i]));
        for(int i=0; i<n-1; i++) maxa=max(maxa,(v[i]-v[0]));
        for(int i=0; i<n; i++){
            if(i==n-1){
                maxa=max((v[i]-v[0]),maxa);
            }
            else{
                maxa=max(maxa,(v[i]-v[i+1]));
            }
        }
        cout<<maxa<<endl;
    }
}