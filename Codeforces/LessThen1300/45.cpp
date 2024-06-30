#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    long long n;
    cin>>n;
    long long a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    long long m;
    cin>>m;
    long long b[m];
    for(int i=0; i<m; i++){
        cin>>b[i];
    }
    long long g[m*n];
    long long h=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            long long w=b[j]/a[i];
            if(w*a[i]==b[j]){
                g[h]=w;
            }
            else{
                g[h]=-1;
            }
            h++;
        }
    }
    long long f=g[0];
    for(int i=0; i<m*n; i++){
        if(f<g[i]){
            f=g[i];
        }
    }
    long long count=0;
    for(int i=0; i<m*n; i++){
        if(g[i]==f){
            count++;
        }
    }
    cout<<count;
}