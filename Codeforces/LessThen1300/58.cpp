#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string s;
    cin>>s;
    bool h=false;
    bool e=false;
    bool l1=false;
    bool l2=false;
    bool o=false;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='h' && h==false && e==false && l1==false && l2==false && o==false){
            h=true;
        }
        else if(s[i]=='e' && h==true && e==false && l1==false && l2==false && o==false){
            e=true;
        }
        else if(s[i]=='l' && h==true && e==true && l1==false && l2==false && o==false){
            l1=true;
        }
        else if(s[i]=='l' && h==true && e==true && l1==true && l2==false && o==false){
            l2=true;
        }
        else if(s[i]=='o' && h==true && e==true && l1==true && l2==true && o==false){
            o=true;
        }
    }
    if(h==true && e==true && l1==true && l2==true && o==true){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
}