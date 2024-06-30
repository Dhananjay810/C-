#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
void generateBinary(string ans,int n){
    if(ans.size()==n){
        cout<<ans<<endl;
        return;
    }
    generateBinary(ans+'0',n);
    char ch=ans[ans.size()-1];
    if(ans=="" || ch=='0') generateBinary(ans+'1',n);
}
int main(){
    int n;
    cin>>n;
    generateBinary("",n);
}