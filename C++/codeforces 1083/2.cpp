#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;

bool isPrime(int n){
    if(n==1) return false;
    for(int i=2; i<=sqrt(n); i++){
        if(n%i==0){
            // fac=i;
            return false;
        }
    } 
    return true;
}

vector<int> fac(long long int a){
    vector<int> aa;
    int j;
    for(j=2; j<sqrt(a); j++){
        if(a%j==0){
            if(isPrime(j)==true) aa.push_back(j);
        }
    }
    for(j=sqrt(a); j>1; j--){
        if(a%j==0){
            if(isPrime(a/j)==true) aa.push_back(a/j);
        }
    }
    return aa;
}

vector<long long> uniquePrimeFactors(long long n) {
    vector<long long> factors;

    if (n % 2 == 0) {
        factors.push_back(2);
        while (n % 2 == 0) n /= 2;
    }

    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            factors.push_back(i);
            while (n % i == 0) n /= i;
        }
    }

    if (n > 1)
        factors.push_back(n);

    return factors;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        long long int n;
        cin>>n;
        long long int ans=1;
        vector<long long> a=uniquePrimeFactors(n);
        for(int i=0; i<a.size(); i++) ans=ans*a[i];
        cout<<ans<<endl;
    }
}