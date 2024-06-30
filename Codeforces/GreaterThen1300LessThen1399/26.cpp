#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    for(int i=0; i<n; i++){
        int u=0;
        u=180-arr[i];
        if(360%u==0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}