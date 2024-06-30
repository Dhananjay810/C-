#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    int m;
    int y=1000000000;
    int o=0;
    int u=0;
    string s[n];
    for(int i=0; i<n; i++){
        cin>>m;
        s[i]= to_string(m);
        if(m<y){
            y=m;
            u=i+1;
        }
        
    }
    string t= to_string(y);
    for(int i=0; i<n; i++){
        if(s[i]==t){
            o=o+1;
        }
    }
    if(o>1){
        cout<<"Still Rozdil";
    }
    else if(n==1){
        cout<<n;
    }
    else cout<<u;
  
}