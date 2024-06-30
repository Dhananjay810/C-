#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string a;
    cin>>a;
    string b;
    cin>>b;
    string c;
    cin>>c;
    string d=a+b;
   // cout<<d;
    bool flag=false;
    if(d.size()!=c.size()) cout<<"NO";
    else{
        sort(d.begin(),d.end());
        sort(c.begin(),c.end());
        for(int i=0; i<d.size(); i++){
            if(d[i]==c[i]){
                flag=true;
            }
            else{
                flag=false;
                break;
            }
        }
        if(flag==true) cout<<"YES";
        else cout<<"NO";
    }
    
}