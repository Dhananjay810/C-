#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int h;
    cin>>h;
    long long a[h];
    for(int i=0; i<h; i++){
        cin>>a[i];
    }
    int u=0;
    long long k=1;
    long long count=0;
    for(int i=0; i<h; i++){
        u++;
        if(a[i]>k){
            count=count+abs(a[i]-k);
            k=a[i];
        }
        else if(a[i]<k){
            count=count +(abs(n-k)+abs(a[i]-1))+1;
            k=a[i];
        }
    }
    cout<<count;
}