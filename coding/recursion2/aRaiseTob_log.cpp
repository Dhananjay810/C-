#include<iostream>
using namespace std;
int power(int a, int b){
    if(b==1) return a;
    int ans;
    ans=power(a,b/2);
    if(b%2==0){ 
        return ans*ans;
    }
    return ans*ans*a;
}
int main(){
    int a,b;
    cin>>a>>b;
    cout<<power(a,b);
}