#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
void sub(string ans,string s,int idx,int n,vector<string>& s1){
    if(idx==n){
        s1.push_back(ans);
        return;
    }
    sub(ans,s,idx+1,n,s1);
    if(ans=="" || ans[ans.size()-1]==s[idx-1]){
        ans=ans+s[idx];
        sub(ans,s,idx+1,n,s1);
    }
}
int main(){
    string s="coaching";
    string t="coding";

    vector<string> s1;
    int n=s.size();
    sub("",s,0,n,s1);

    int m=t.size();
    vector<string> s2;
    sub("",t,0,m,s2);
    sort(s2.begin(),s2.end());
    reverse(s2.begin(),s2.end());
    sort(s1.begin(),s1.end());
    reverse(s1.begin(),s1.end());
    // for(int i=0; i<s2.size(); i++){
    //     bool flag=false;
    //     for(int j=0; j<s1.size(); j++){
    //         if(s2[i]==s1[j]){
    //             flag=true;
    //             break;
    //         }
    //         if(s2[j].size()<s1[i].size()) break;
    //     }
    //     if(flag==true){
    //         cout<<t.size()-s2[i].size();
    //         break;
    //     }
    // }
}