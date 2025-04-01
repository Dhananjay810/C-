#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;

void f(string &in, int i, int n){
    if(i==n){
        cout<<in<<endl;
        return;
    }
    unordered_set<char> set;
    for(int j=i; j<n; j++){

        if(set.find(in[j])!=set.end()) continue;
        set.insert(in[j]);
        
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