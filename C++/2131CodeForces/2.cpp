#include<iostream>
#include<vector>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> ans(n);
        bool flag=false;
        for(int i=0; i<n; i++){
            if(flag==false){
                ans[i]=-1;
                flag=true;
            }
            else{
                ans[i]=3;
                flag=false;
            }
        }
        if(n%2==0) ans[n-1]=2;
        for(int i=0; i<n; i++) cout<<ans[i]<<" ";
        cout<<endl;
    }
}