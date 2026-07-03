#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        unordered_set<int> set;
        int u=0;
        for(int i=0; i<n; i++){
            set.insert(u);
            if(s[u]=='R') u++;
            else break;
            // else u--;
        }
        cout<<set.size()<<endl;
    }
}