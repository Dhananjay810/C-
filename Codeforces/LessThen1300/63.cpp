#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    int y=1;
    vector<int> v;
    for(int i=0; i<s.size()-1; i++){
        if(s[i] == s[i+1]) y++;
        else{
            v.push_back(y);
            y=1;
        }
    }
    v.push_back(y);
    int o=0;
    for(int i=0; i<v.size(); i++){
        if(v[i]%2!=0) o++;
    }
    if(o<=1){
        cout<<"First";
        return 0;
    }
    if(o>1) o -= 1;
    if(o%2==0) cout<<"First";
    else cout<<"Second";
}