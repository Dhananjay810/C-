#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<bool> v(n+1,false);
    for(int i=0; i<n-1; i++){
        int num;
        cin>>num;
        v[num]=true;
    }
    int i=1;
    while(v[i]!=false) i++;
    cout<<i;
}