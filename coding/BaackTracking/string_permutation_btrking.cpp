#include<iostream>
#include<string>
using namespace std;

void f(string &in, int i, int n){
    if(i==n){
        cout<<in<<endl;
        return;
    }

    for(int j=i; j<n; j++){
        swap(in[j],in[i]);
        f(in,i+1,n);
        swap(in[j],in[i]);
    }
}

int main(){
    string s;
    cin>>s;
    f(s,0,s.size());
}