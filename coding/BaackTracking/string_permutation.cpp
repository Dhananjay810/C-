#include<iostream>
#include<string>
using namespace std;

void f(string s, string out){

    if(s.size()==0){
        cout<<out<<endl;
        return;
    }

    for(int i=0; i<s.size(); i++){
        string left=s.substr(0,i);
        string right=s.substr(i+1);

        f(left+right,out+s[i]);
    }
}

int main(){
    string s;
    cin>>s;
    f(s,"");
}