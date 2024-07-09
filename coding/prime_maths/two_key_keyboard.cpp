#include<iostream>
#include<vector>
#include<algorithm>
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

    void fact(int n,vector<int>& prime){
        int j;
        for(j=2; j<sqrt(n); j++){
            if(n%j==0){
              //  cout<<j<<" ";
                if(isPrime(j)) prime.push_back(j);
            }
        }
        for(j=sqrt(n); j>1; j--){
            if(n%j==0){
             //   cout<<n/j<<" ";
                if(isPrime(n/j)) prime.push_back(n/j);
            }
        }
    }

int main(){
    int n;
    cin>>n;
    if(isPrime(n)) cout<<n;
        vector<int>prime;
        fact(n,prime);
        int count=0;
        for(int i=0; i<prime.size(); i++){
            int m=n;
            int ele=prime[i];
            while(m%ele==0){
                count= count+ele;
                m=m/ele;
            }
        }
        cout<<count;
}