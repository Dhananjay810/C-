#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int n;
    cin>>n;
    // met->1  O(n)
    // int i;
    // for(i=1; i<=n; i++){
    //     if(n%i==0) cout<<i<<" ";
    // }
    
    // met->2  O(sqrt(n))
    int j;
    for(j=1; j<sqrt(n); j++){
        if(n%j==0){
            cout<<j<<" ";
        }
    }
    for(j=sqrt(n); j>=1; j--){
        if(n%j==0){
            cout<<n/j<<" ";
        }
    }

}