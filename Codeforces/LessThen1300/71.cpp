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
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    int count=0;
    int k=2;
    int i=0;
    while(count!=n){
        if(isPrime(k)){
            v[i]=k;
            i++;
            count++;
        }
        k++;
    }
    for(int i=0; i<n; i++) cout<<v[i]<<" ";
}