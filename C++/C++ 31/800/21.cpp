#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int ans=-1;
        int temp=0;
        for(int i=0; i<n; i++){
            int num;
            cin>>num;
            if(num==0) temp++;
            else{
                ans=max(ans,temp);
                temp=0;
            }
        }
        ans=max(ans,temp);
        cout<<ans<<endl;
    }
}