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
    int low=0;
    int high=n-1;
    int idx=-1;
    bool flag=false;
    while(high>=low){
        int mid=low+(high-low)/2;
        if(v[mid]==v[mid+1] || v[mid]==v[mid-1]){
            cout<<v[mid];
            flag=true;
            break;
        }
        else if(mid+1<v[mid]) high=mid-1;
        else low=mid+1;
    }
    if(flag==false) cout<<"-1";
}