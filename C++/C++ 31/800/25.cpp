#include<iostream>
#include<string>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int ans=0;
        int i=0; int j=n-1;
        while(i<j && s[i]!=s[j]){
            i++;
            j--;
        }
        ans=(j-i)+1;
        cout<<ans<<endl;
    }
}