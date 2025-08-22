#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
using namespace std;
bool check(int mid, vector<int>& v, int h){
    int n=v.size();
    int count=0;
    for(int i=0; i<n; i++){
        int hr,l;
        hr=v[i]/mid;
        if(hr*mid==v[i]) l=hr;
        else l=hr+1;
        count=count+l;
    }
    if(count<=h) return true;
    else return false;
}
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n;i++){
        cin>>v[i];
    }
    int h;
    cin>>h;
    int u=INT_MIN;
    for(int i=0; i<n; i++){
        if(u<v[i]){
            u=v[i];
        }
    }
    int low=0;
    int high=u;
    int c=0;
    while(high>=low){
        int mid=low+(high-low)/2;
        if(check(mid,v,h)){
            c=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    cout<<c;
}