#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    cin>>s;
    int n=s.size();
    int ans=1;
    int i=0;
    while(i<n){
        char ch=s[i];
        int y=0;
        while(s[i]==ch){
            y++;
            i++;
        }
        ans=max(ans,y);
    }
    cout<<ans;
}