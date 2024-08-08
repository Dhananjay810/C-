#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int a,b,n;
    cin>>a>>b>>n;
    int h=a*10;
    int mod=h%b;
    int k=b-mod;
    if(mod!=0 && k>9){
        cout<<"-1";
        return 0;
    }
    else if(mod!=0){
        h=h+k;
        a=h;
        n--;
    }
    string s=to_string(a);
    for(int i=0; i<n; i++) s=s+"0";
    cout<<s;
}