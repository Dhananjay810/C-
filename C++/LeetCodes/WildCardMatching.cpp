#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool check(string p, string s, int y){
    bool flag=false;
    for(int i=0; i<s.size(); i++){
        if(p[y]==s[i]){
            flag=true;
            break;
            }
    }
    if(flag==true) return true;
    return false;
}
int ind(string p, string s, int y){
        int idx=-1;
    for(int i=0; i<s.size(); i++){
        if(p[y]==s[i]){
            idx=i;
            break;
            }
    }
    return idx;
}
int main(){
    string s;
    cin>>s;
    string p;
    cin>>p;
    int m=s.size();
    int n=p.size();
    bool flag=false;
    for(int i=0; i<n; i++){
        if(p[i]=='*'){
            flag=true;
            break;
        }
    }
    bool g=false;
    if(flag==false){
        if(m!=n) cout<<"FALSE";
        else{
            for(int i=0; i<m; i++){
                if(s[i]==p[i] || p[i]=='?'){
                    g=true;
                }
                else{
                    g=false;
                    break;
                }
            }
        }
    }
    else if(flag==true){
        int j=0;
       for(int i=0; (i<n && j<m); i++){
        if(p[i]!='*'){
            if(s[j]==p[i] || p[i]=='?'){
                j++;
                g=true;
            }
            else{
                g=false;
                break;
            }
        }
        else if(p[i]=='*'){
            if(i<n-1 && p[i+1]!='*'){
                i++;
                if(p[i]=='?'){
                    g=true;
                    i++;
                    j++;
                }
                else if(check(p,s,i)){
                    j=ind(p,s,i);
                    if(s[j]==p[i]){
                        g=true;
                        j++;
                    }
            }
            else{
                g=false;
                break;
            }
        }
        else{
            g=true;
        }
       }
    }
}

    cout<<g;
}