#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
void gen(string ans,int n,int op,int cl){
    if(cl==n){
        cout<<ans<<endl;
        return;
    }
    if(op<n){
        gen(ans+'(',n,op+1,cl);
    }
    if(cl<op){
        gen(ans+')',n,op,cl+1);
    }
}
int main(){
    int n;
    cin>>n;
    gen("",n,0,0);
}