#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int longestIdealString(string s, int k) {
        int n=s.size();
        sort(s.begin(),s.end());
        int t=-1;
        int u=1;
        int v=0;
        for(int i=0; i<n-1; i++){
            if(u==1){
                if(abs((int)s[v]-(int)s[v+1])<=k){
                    u=u+1;
                }
                else{
                    if(u>t) t=u;
                    u=1;
                }
            }
            else{
                if(abs((int)s[v]-(int)s[v+2])<=k){
                    u++;
                    v++;
                }
                else{
                    if(u>t) t=u;
                    u=1;
                    v=0;
                }
            }
        }
        return t;
    }

int main(){
    string s;
    cin>>s;
    int k;
    cin>>k;
    cout<<longestIdealString(s,k);
}