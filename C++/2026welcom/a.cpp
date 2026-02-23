#include<iostream>
#include<vector>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        int zero=0;
        for(int i=0; i<n; i++){
            int num;
            cin>>num;
            v[i]=num;
            zero++;
        }
        if(v[0]==1 || v[n-1]==1){
            cout<<"Alice"<<endl;
        }
        else cout<<"Bob"<<endl;
    }
}