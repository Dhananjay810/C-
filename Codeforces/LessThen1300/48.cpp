#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v(12);
    for(int i=0; i<12; i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int count=0;
    int b=0;
    int e=11;
    while(count<n){
        count = count + v[e];
        b++;
        e--;
    }
    if(b>12) cout<<"-1";
    else cout<<b;
}