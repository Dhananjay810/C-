#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0; i<n; i++) cin>>a[i];
        sort(a.begin(),a.end());
        int y=a[n-1];
        vector<int> c;
        while(a.size()>0 && a[a.size()-1]==y){
            c.push_back(a[a.size()-1]);
            a.pop_back();
        }
        if(a.size()==0){
            cout<<"-1"<<endl;
            continue;
        }
        cout<<a.size()<<" "<<c.size()<<endl;
        for(int i=0; i<a.size(); i++) cout<<a[i]<<" ";
        cout<<endl;
        for(int i=0; i<c.size(); i++) cout<<c[i]<<" ";
        cout<<endl;
    }
}