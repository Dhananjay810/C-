#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
bool check(long long trip,vector<int>& v, int totaltrip){
    int n=v.size();
    long long count=0;
    for(int i=0; i<n; i++){
        count=count+v[i]/trip;
    }
    if(count>(long long)totaltrip) return false;
    else return true;
}
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    int c=-1;
    for(int i=0; i<n; i++){
        c=max(c,v[i]);
    }
    int totaltrip;
    cin>>totaltrip;
    int low=1;
    int high=totaltrip*c;
    int ans=-1;
    while(high>=low){
        long long mid=low+(high-low)/2;
        if(check(mid,v,totaltrip)){
            ans=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    cout<<ans;
}