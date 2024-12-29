#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];

    sort(v.begin(),v.end());

    int k=1;
    for(int i=0; i<n; i++){
        if(v[i]!=k){
            cout<<k;
            return 0;
        }
        k++;
    }
    cout<<k;
}