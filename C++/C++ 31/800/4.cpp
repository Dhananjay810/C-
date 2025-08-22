#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if((n+1)%3==0){
            cout<<"First"<<endl;
            continue;
        }
        else if((n-1)%3==0){
            cout<<"First"<<endl;
            continue;
        }
        cout<<"Second"<<endl;
    }
}