#include<iostream>
#include<climits>
using namespace std;
int main(){
    int n;
    cin>>n;
    int mini=100005;
    int maxa=-100005;
    for(int i=0; i<n; i++){
        int num;
        cin>>num;
        if(num==0){
            cout<<"0";
            return 0;
        }
        else if(num>0){
            mini=min(num,mini);
        }
        else if(num<0){
            maxa=max(num,maxa);
        }
    }
    maxa=(-1)*maxa;
    // cout<<maxa<<" "<<mini;
    cout<<min(maxa,mini);
}