#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int x,y;
        cin>>x>>y;
        if(x%2==0 && y%2==0){
            cout<<"YES"<<endl;
            continue;
        }
        else{
            if((x%2==0 && y%2==1) || (x%2==1 && y%2==0)){
                cout<<"YES"<<endl;
                continue;
            }
            else{
                cout<<"NO"<<endl;
                continue;
            }
        }
    }
}