/*
we only apply binary searcing 
only when element are in sorted
eithre ascending Or decending 
OTher wise we use linear searching*/

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
    int y=0;
    cin>>y;
    bool flag =false;
    sort(v.begin(),v.end());
    int low=0;
    int high=n-1;
    for(int i=0; i<n; i++){
        int mid = (high+low)/2;
        if(v[mid]==y){
            flag=true;
            break;
        }
        if(mid<y){
            low=mid+1;
        }
        if(mid>y){
            high=mid-1;
        }

    }
    if(flag==true) cout<<"YES";
    else cout<<"NO";
}