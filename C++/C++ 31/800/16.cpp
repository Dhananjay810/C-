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
        bool f=false;
        for(int i=0; i<n-1; i++){
            if(v[i]>v[i+1]){
                cout<<"0"<<endl;
                f=true;
                break;
            }
        }
        if(f==true) continue;
        int mini=INT_MAX;
        for(int i=0; i<n-1; i++){
            int y=(v[i+1]-v[i]);
            // cout<<y<<" ";
            mini=min(mini,(y/2)+1);
        }
        cout<<mini<<endl;
    }
}