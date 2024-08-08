#include<iostream>
#include<cmath>
using namespace std;
int main(){
    long long n;
    cin>>n;
    long long count=0;
    for(long long i=1; i<n; i++){
        for(long long j=i+1; j<=n; j++){
                double k=sqrt(i*i+j*j);
                if(k<=n && k==(int)k){
                    count++;
                }
            
        }
    }
    cout<<count;
}