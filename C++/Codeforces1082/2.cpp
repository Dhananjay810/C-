#include<iostream>
#include<vector>
#include<string>
using namespace std;
bool f(char st, char en, string s){
    if(s.size()==0) return true;
    char x=s[0];
    if(x=='?' || (x==st && x==en)){
        string a=s.substr(1,s.size()-1);
        string b=s.substr(0,s.size()-1);
        if(st=='a') {
            bool xx = f('b', en, a);
            if(xx==true) return true;
        }
        else {
            bool xx = f('a', en, a);
            if(xx==true) return true;
        }
        if(en=='a') {
            bool xx = f(st, 'b', b);
            if(xx==true) return true;
        }
        else {
            bool xx = f(st, 'a', b);
            if(xx==true) return true;
        }
    }
    else if(x=='a'){
        if(st=='b' && en=='b') return false;
        if(st=='a'){
            string a=s.substr(1,s.size()-1);
            bool xx = f('b', en, a);
            if(xx==true) return true;
        }
        else if(en=='a'){
            string b=s.substr(0,s.size()-1);
            bool xx = f(st, 'b', b);
            if(xx==true) return true;
        }
        else{

        }
    }
    else{
        if(st=='a' && en=='a') return false;

        if(st=='b'){
            string a=s.substr(1,s.size()-1);
            bool xx=f('a', en, a);
            if(xx==true) return true;
        }
        else if(en=='b'){
            string b=s.substr(0,s.size()-1);
            bool xx= f(st, 'a', b);
            if(xx==true) return true;
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        char st='a';
        char en='a';
        if(n%2==0) en='b';
        if(f(st, en, s)==true) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
