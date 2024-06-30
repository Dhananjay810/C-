#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    int hun=0;
    int thun=0;
    for(int i=0; i<n; i++){
        cin>>v[i];
        if(v[i]==100) hun++;
        else thun++;
    }
    if(hun%2!=0){
        cout<<"NO";
        return 0;
    }
    else if(hun==0){
        if(thun%2==0) cout<<"YES";
        else cout<<"NO";
        return 0;
    }
    else{
        cout<<"YES";
        return 0;
    }
    // else if(hun%2==0 && thun==0){
    //     cout<<"YES";
    //     return 0;
    // }
    // int t=thun+hun;
    // if(){
    //     cout<<"NO";
    //     return 0;
    // }
    // else cout<<"YES";
}