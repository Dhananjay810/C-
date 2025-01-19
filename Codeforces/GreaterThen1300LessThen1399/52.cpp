#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

bool isPrime(int n){
    if(n==1) return false;
    for(int i=2; i<=sqrt(n); i++){
        if(n%i==0){
            return false;
        }
    } 
    return true;
}

int main(){
    long long n;
    cin>>n;
    for(int i=0; i<n; i++){
        long long num;
        cin>>num;
        double h=sqrt(num);
        long long j=sqrt(num);
        if(h!=j){
            cout<<"NO"<<endl;
            continue;
        }
        if(isPrime(j)==true){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }
}