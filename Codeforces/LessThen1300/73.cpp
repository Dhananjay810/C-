#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string n;
    cin>>n;
    bool  flag=false;
    string t="";;
    for(int i=0; i<n.size(); i++){
        if(n[i]=='0' && flag==false){
            flag=true;
            continue;
        }
        else{
            t=t+n[i];
        }
    }
    if(n==t) t.pop_back();
    cout<<t;
}