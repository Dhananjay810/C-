#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int max(vector<int>& v){
    int hi=v[0];
    int idx=0;
    for(int i=0; i<v.size(); i++){
        if(hi<v[i] && v[i]>0){
            hi=v[i];
            idx=i;
        }
        else continue;
    }
    return idx;
}
int main(){
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    vector<int> v;
    string t;
    for(int i=0; i<s.size(); i++){
        int count=1;
        t.push_back(s[i]);
        bool flag=false;
        int j=i;
        while(flag==false){
            if(s[j]==s[j+1]){
                count++;
            }
            else{
                flag=true;
                i=j;
            }
            j++;
        }
        v.push_back(count);
    }
    // cout<<t<<endl;
    // for(int i=0; i<v.size(); i++){
    //     cout<<v[i]<<" ";
    // }
    string f;
    for(int i=0; i<v.size(); i++){
        int m=max(v);
        for(int i=0; i<v[m]; i++){
            f.push_back(t[m]);
        }
        v[m]=-1;
    }
    cout<<f;
}