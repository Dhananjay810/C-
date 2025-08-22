#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
bool check(string s, string t, int j){
    if(s.size()!=t.size()) return false;
    for(int i=0; i<s.size(); i++){
        for(int j=0; j<t.size(); j++){
            if(s[i]==t[j]){
                t[j]='0';
                break;
            }
            else if(s[i]!=t[j] && j==t.size()-1) return false;
        }
    }
    return true;
}
int main(){
    int n;
    cin>>n;
    vector<string> strs(n);
    for(int i=0; i<n; i++){
        cin>>strs[i];
    }
   
    vector<vector<string>> c;
    for(int i=0; i<n; i++){
        string s=strs[i];
        for(int j=i; j<n; j++){
            string t=strs[j];
            if(check(s,t,j)){
                c[i].push_back(strs[j]);
                string q="##";
                strs[j]=q;
            }
        }
    }
    for(int i=0; i<c.size(); i++){
        for(int j=0; j<c[i].size(); j++){
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }
}