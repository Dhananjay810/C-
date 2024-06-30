#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    int a;
    cin>>a;
    int b;
    cin>>b;
    int c=a+b;
    string w;
    w=to_string(c);
    string x;
    for(int i=0; i<w.size(); i++){
        if(w[i]!='0'){
            x=x+w[i];
        }
    }
    w=to_string(a);
    string k;
    for(int i=0; i<w.size(); i++){
        if(w[i]!='0'){
            k=k+w[i];
        }
    }
    int p;
    p=stoi(k);
    string y;
    y=to_string(b);
    string z;
    for(int i=0; i<y.size(); i++){
        if(y[i]!='0'){
            z=z+y[i];
        }
    }
    int q;
    q=stoi(z);
    int r=p+q;
    string j;
    j=to_string(r);
    if(j==x) cout<<"YES";
    else cout<<"NO";
}