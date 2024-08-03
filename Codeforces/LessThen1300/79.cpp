#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    string m;
    cin>>m;
    vector<char> f(n);
    vector<char> s(n);
    for(int i=0;i<n;i++){
        f[i]=m[i];
    }
    for(int i=0; i<n; i++){
        s[i]=m[i+n];
    }
    sort(f.begin(),f.end());
    sort(s.begin(),s.end());

    bool flag;
    for(int i=0;i<n;i++){
        if(f[i]==s[i]){
            cout<<"NO";
            return 0;
        }
    }
    if(f[0]<s[0]) flag=true;
    else flag=false;
    if(flag==true){
        for(int i=0;i<n;i++){
            if(f[i]>s[i]){
                cout<<"NO";
                return 0;
            }
        }
    }
    if(flag==false){
        for(int i=0;i<n;i++){
            if(f[i]<s[i]){
                cout<<"NO";
                return 0;
            }
        }
    }
    cout<<"YES";
    // for(int i=0; i<n; i++) cout<<f[i]<<" ";
    // cout<<endl;
    // for(int i=0; i<n; i++) cout<<s[i]<<" ";

}