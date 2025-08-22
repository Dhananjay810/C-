#include<iostream>
#include<vector>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> ans;
        int lim=0;
        if(n%2==0) lim=n-1;
        else lim=n;
        for(int i=1; i<=lim; i+=2){
            ans.push_back(i);
        }
        if(lim==n-1) ans.push_back(n);
        int i=n-2;
        if(n%2!=0) i=n-1;
        for(i; i>1; i-=2){

            ans.push_back(i);
        }
        for(int a=0; a<n; a++) cout<<ans[a]<<" ";
        cout<<endl;
    }
}