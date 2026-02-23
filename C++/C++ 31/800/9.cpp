#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int a;
        cin>>a;
        int ans=0;
        for(int i=0; i<a-1; i++){
            int num;
            cin>>num;
            ans+=num;
        }
        cout<<(-1)*ans<<endl;
    }
}