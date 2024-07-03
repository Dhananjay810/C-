#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    int mod=100000000+7;
    vector<long long int> fact(n+1,1);
    for(int i=2; i<n; i++){
        fact[i]=((i%mod)*(fact[i-1]%mod)%mod);
    }

    for(int i=0; i<n; i++){
        cout<<i<<" "<<"!->"<<" "<<fact[i]<<endl;;
    }
}