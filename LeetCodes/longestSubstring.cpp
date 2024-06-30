#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string s;
    cin>>s;
    int n=s.size();
    int count=0;
    vector<int> v;
    for(int i=0; i<n; i++){
    bool flag=false;
        for(int j=0; j<i; j++){
            if(s[i]==s[j]){
                flag=false;
                break;
            }
            else{
                flag=true;
            }
        }
        if(flag==true || i==0) count++;
        else{
            v.push_back(count);
            count=1;
        }
    }
    for(int i=0;i<v.size(); i++){
        cout<<v[i]<<" ";
    }
}