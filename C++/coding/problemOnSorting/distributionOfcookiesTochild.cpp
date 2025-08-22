#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    vector<int> w(m);
    for(int i=0; i<m; i++){
        cin>>w[i];
    }
    int h=0;
    sort(v.begin(),v.end());
    sort(w.begin(),w.end());
    for(int i=0; i<m; i++){
        if(w[i]>=v[i]){
            h++;
        }
    }
    cout<<h;
}