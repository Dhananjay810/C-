#include<iostream>
#include<string>
using namespace std;
int main(){
    int n,t;
    //cout<<"enter no. of student : ";
    cin>>n;
   // cout<<"enter no. of swap : ";
    cin>>t;
    string s;
   // cout<<"enter sequence : ";
    cin>>s;
    for(int i=0; i<t; i++){
        for(int j=0; j<s.length(); j++){
            if(s[j]=='B' && s[j+1]!='B' && j+1!=s.length()){
                swap(s[j],s[j+1]);
                j += 1;
            }
       }
    }
    cout<<s;
}