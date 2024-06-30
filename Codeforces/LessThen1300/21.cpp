#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<long long> n(4);
    for(int i=0; i<4; i++){
        cin>>n[i];
    }
    sort(n.begin(),n.end());
    int same =0;
    for(int i=0; i<3; i++){
        if(n[i]==n[i+1]) same++;
    }
    cout<<same;
}