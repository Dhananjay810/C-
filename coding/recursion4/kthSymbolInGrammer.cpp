#include<iostream>
using namespace std;
int sym(int n,int k){
    if(n==1) return 0;
    if(k%2==0){
        int ans=sym(n-1,k/2);
        if(ans==0) return 1;
        else return 0;
    }
    else{
        return sym(n-1,k/2+1);
    }
}
int main(){
    int n,k;
    cin>>n>>k;
    cout<<sym(n,k);
}