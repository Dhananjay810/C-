#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    int  y;
    cin>>y;
    for(int i=0; i<n; i++){
        if(v[i]>y){
            cout<<v[i-1];
            break;
        }
    }
}