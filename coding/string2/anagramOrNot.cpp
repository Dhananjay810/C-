#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string m,n;
    cout<<"enter two string : ";
    cin>>m>>n;
    sort(m.begin(),m.end());
    sort(n.begin(),n.end());
    if(m==n){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }

}