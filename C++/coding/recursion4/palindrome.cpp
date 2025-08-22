#include<iostream>
#include<string>
using namespace std;
bool ispallendrom(string s,int i,int j){
    if(i>j) return true;
    if(s[i]!=s[j]) return false;
    else return ispallendrom(s,i+1,j-1);
}
int main(){
    string s;
    cin>>s;
    cout<<ispallendrom(s,0,s.length()-1);
}