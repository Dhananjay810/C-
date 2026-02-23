#include<iostream>
#include<vector>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0; i<n; i++) cin>>a[i];
        int x=n+1;
        for(int i=0; i<n; i++) cout<<(x-a[i])<<" ";
        cout<<endl;
    }
}