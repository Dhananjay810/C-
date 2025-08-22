#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s;
    while(n!=0){
        int v=n%2;
        string e=to_string(v);
        s.push_back(e[0]);
        n=n/2;
    }
    reverse(s.begin(),s.end());
    cout<<s;
}