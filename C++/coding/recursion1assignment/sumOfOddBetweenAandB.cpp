#include<iostream>
using namespace std;
int sum(int a,int b,int ans){
    if(a>b) return ans;
    if(a%2==0) a++;
    ans=ans+a;
    sum(a+2,b,ans);
}
int main(){
    int a,b;
    cin>>a>>b;
    cout<<sum(a,b,0);
}