#include<iostream>
#include<unordered_set>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        unordered_set<int> set;
        for(int i=0; i<n; i++){
            int num;
            cin>>num;
            set.insert(num);
        }
        if(set.find(k)==set.end()) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
}