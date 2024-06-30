#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    string s,t;
    cout<<"enter two string : ";
    cin>>s>>t;
    int x = s.size();
    int y = t.size();
    int i,j;
    sort(s.begin(),s.end());
    cout<<s;
   for(int i = 0; i<x; i++){
        if(i==0){
            if(s[i]==s[i+1])cout<<(int)s[i]<<" "<<endl;
            else continue;
        }
        else if(i==x-1){
            if(s[i]==s[i-1])cout<<(int)s[i]<<" "<<endl;
            else continue;
        }
        else{
            if((s[i]==s[i-1] && (i-1)!= 0) || (s[i]==s[i+1] && (i+1)!=x-1)){
                cout<<(int)s[i]<<" "<<endl;
            }
        }
        
   }
}