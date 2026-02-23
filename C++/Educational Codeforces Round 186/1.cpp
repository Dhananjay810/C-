#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
string finds(string &s, int i, int j){
    string k="";
    for(int l=i; l<=j; l++) k=k+s[l];
    return k;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int i=0,j=3;
        bool flag=false;
        while(j<n){
            string g= finds(s,i,j);
            if(g=="2026"){
                flag=true;
                cout<<"0"<<endl;
                break;
            }
            i++;
            j++;
        }
        if(flag==true) continue;
        i=0;
        j=3;
        while(j<n){
            string g= finds(s,i,j);
            if(g=="2025"){
                flag=true;
                cout<<"1"<<endl;
                break;
            }
            i++;
            j++;
        }
        if(flag==true) continue;
        cout<<"0"<<endl;
    }
}