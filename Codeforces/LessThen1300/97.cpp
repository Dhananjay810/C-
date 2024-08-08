#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    long long int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    vector<long long int> v;
    long long int u=1;
    for(long long int i=0; i<s.size()-1; i++){
        if(s[i]==s[i+1]) u++;
        else{
            v.push_back(u);
            u=1;
        }
    }
    v.push_back(u);
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    long long int count=0;
    long long int i=0;
    while(true){
        int h=k;
        h=h-v[i];
        if(h>=0){
            count = count+(v[i]*v[i]);
            k=k-v[i];
            if(k==0) break;
        }
        else{
            count = count+(k*k);
            break;
        }
        i++;
    }
    cout<<count;
}