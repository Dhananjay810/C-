#include<iostream>
#include<vector>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int ans=0;
        for(int i=0; i<n; i++){
            int num;
            cin>>num;
            ans+=num;
        }
        if(ans%3!=0){
            cout<<"0"<<" "<<"0"<<endl;
        }
        else cout<<"1"<<" "<<"2"<<endl;
    }
}