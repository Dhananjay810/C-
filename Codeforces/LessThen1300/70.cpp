#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string s;
    cin>>s;
    string k;
    cin>>k;
    if(s.size()!=k.size()){
        cout<<"NO";
        return 0;
    }
    // sort(s.begin(),s.end());
    // sort(k.begin(),k.end());
    int count=0;
    for(int i=0; i<s.size(); i++){
        if(s[i]!=k[i]) count++;
        if(count>2){
            cout<<"NO";
            return 0;
        }
    }
    if(count!=2){
        cout<<"NO";
        return 0;
    }
    else{
        sort(s.begin(),s.end());
        sort(k.begin(),k.end());
        for(int i=0; i<s.size(); i++){
            if(s[i]!=k[i]){
                cout<<"NO";
                return 0;
            }
        }
    }
    cout<<"YES";
}