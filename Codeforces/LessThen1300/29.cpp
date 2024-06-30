#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    int x=0;
    string s[n];
    for(int i=0; i<n; i++){
        cin>>s[i];
        if(s[i]=="X++") x++;
        else if(s[i]=="X--") x--;
        else if(s[i]=="++X") ++x;
        else --x;
    }
    cout<<x;
}