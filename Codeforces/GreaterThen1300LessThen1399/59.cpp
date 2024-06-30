#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;

    vector<long long> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    if(k<n){
        for(int i=0; i<k; i++){
        v[i] *= -1;
        }
    }
    
    long long h=0;
    for(int i=0; i<n; i++) h+=v[i];
    cout<<h;
}