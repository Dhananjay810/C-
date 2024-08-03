#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int main(){
    int n;
    cin>>n;
    int j=0;
    vector<int> q(n);
    vector<int> v;
    for(int i=0; i<n; i++){
        cin>>q[i];
        if(q[i]==1){
            v.push_back(j);
            j=0;
        }
        else j++;
    }
    v.push_back(j);

    int idx=-1;
    int mx=INT_MIN;
    for(int i=0; i<v.size(); i++){
        if(v[i]>mx){
            mx=v[i];
            idx=i;
        }
    }
    int x=idx-1,y=idx+1;
    while(x>=0){
        if(v[x]==0){
            mx++;
            x--;
        }
        else break;
    }
    while(y<v.size()){
        if(v[y]==0){
            mx++;
            y++;
        }
        else break;
    }
    //cout<<mx;
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
}