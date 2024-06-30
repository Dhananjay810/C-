#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    vector<int> l;
    for(int i=0; i<n; i++){
        l.push_back(v[i]);
    }
    sort(v.begin(),v.end());
    int b=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(l[j]==v[i]){
                l[j]=b;
                b++;
                break;
            }
            else continue;
        }
    }
    for(int i=0; i<n; i++){
        cout<<l[i]<<" ";
    }
}