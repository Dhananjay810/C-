#include<iostream>
#include<string>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        string a;
        cin>>a;
        string b;
        cin>>b;
        if(a==b) cout<<"0"<<endl;
        int i=0,j=0;
        int ans=0;
        while(i<n && j<m){
            if(a[i]==b[j]) j++;
            else{
                if(j!=0){
                    j=0;
                    ans=0;
                    i--;
                }
            }
            i++;
            if(i!=0){
                if(i==n && a[0]==b[j]){
                    i=0;
                    ans++;
                }
            }
        }
        if(ans!=0) cout<<ans<<endl;
        else cout<<"-1"<<endl;
    }
}