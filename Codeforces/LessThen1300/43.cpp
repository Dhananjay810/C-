#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string s;
    cin>>s;
    string h;
    cin>>h;
    string m[s.length()];
    for(int i=0; i<s.length(); i++){
        m[i]=h[i];
    }
    // for(int i=0; i<s.length(); i++)
    // {
    //     cin>>h[i];
    // }
    int j=0;
   // string h=reverse(s.begin(),s.end());
   string u[s.length()];
   for(int i=0; i<s.length(); i++){
        u[i]=s[(s.length()-1)-i];
   }
  for(int i=0; i<s.length(); i++){
   // cout<<u[i];
    if(m[i]==u[i]){
        j++;
    }
    else{
        cout<<"NO";
        break;    }
  }
  if(j==s.length()){
    cout<<"YES";
  }
  
    
}