#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string s;
    cin>>s;
    int count=0;
    bool flag=false;
    for(int i=0; i<s.size()-1; i++){
        if(s[i]==s[i+1]){
            count++;
        }
        else if(s[i]!=s[i+1]){
            if(count+1>=7){
                flag=true;
                break;
            }
            else{
                count=0;
            }
        }
        if(flag==true) break;
    }
    if(flag==true || count+1>=7) cout<<"YES";
    else cout<<"NO";
}