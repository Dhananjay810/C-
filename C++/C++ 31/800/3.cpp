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
        int tot=0;
        int ans=0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='#'){
                ans=0;
            }
            else{
                ans++;
                tot++;
            }
            if(ans==3){
                cout<<2<<endl;
                break;
            }
        }

        if(ans!=3) cout<<tot<<endl;
    }
}