#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int> v={1,2,3,4,5,5,10};
    for(int i=1; i<v.size(); i++){
        v[i]=v[i]+v[i-1];
    }
    for(int i=0; i<v.size(); i++){
        if(2*v[i]==v[v.size()-1]){
            cout<<"Yes"<<" "<<i;
            return 0;
        }
    }
    cout<<"No";
}