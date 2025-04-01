#include<iostream>
#include<vector>
#define ulli unsigned long long int
using namespace std;
int main(){
    ulli n,p,k;
    cin>>n>>p>>k;
    vector<ulli> f(n);
    for(int i=0; i<n; i++) cin>>f[i];
    ulli ans=0;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if((f[i] ^ f[j])*((f[i]*f[i]) ^ (f[j]*f[j]))==k%p) ans++;
        }
    }
    cout<<ans;
}