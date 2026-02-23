#include<iostream>
using namespace std;
int main(){
    long long int t;
    cin>>t;
    while(t--){
        long long int r,c;
        cin>>r>>c;
        bool flag=false;
        long long int y=c;
        if(r>c){
            flag=true;
            y=r;
        }
        long long int ans=0;
        if(flag==false){
            if(y%2==0){
                ans=((y-1)*(y-1))+1;
                ans=ans+(r-1);
                cout<<ans;
            }
            else{
                ans=((y)*(y));
                ans=ans-(r-1);
                cout<<ans;
            }
        }
        else{
            if(y%2==0){
                ans=((y)*(y));
                ans=ans-(c-1);
                cout<<ans;
            }
            else{
                ans=((y-1)*(y-1))+1;
                ans=ans+(c-1);
                cout<<ans;
            }
        }
        cout<<endl;
    }
}