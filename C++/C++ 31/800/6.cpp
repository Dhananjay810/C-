#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0; i<n; i++) cin>>v[i];
        if(n<=2){
            cout<<"YES"<<endl;
            continue;
        }
        unordered_map<int,int> m;
        for(int i=0; i<n; i++) m[v[i]]++;
        if(m.size()==1){
            cout<<"YES"<<endl;
            continue;
        }
        if(m.size()==2){
            vector<int> j;
            for(auto x : m) j.push_back(x.second);
            if(n%2==0){
                if(j[0]==j[1]){
                    cout<<"YES"<<endl;
                    continue;
                }
                else{
                    cout<<"NO"<<endl;
                    continue;
                }
            }
            else{
                if(abs(j[0]-j[1])==1){
                    cout<<"YES"<<endl;
                    continue;
                }
                else{
                    cout<<"NO"<<endl;
                    continue;
                }
            }
        }
        else cout<<"NO"<<endl;
    }
}