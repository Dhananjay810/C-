#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
bool check(int mid,vector<int>& a,int days){
    int m=mid;
    int n=a.size();
    int count=1;
    for(int i=0; i<n; i++){
        if(m>=a[i]){
            m=m-a[i];
        }
        else{
            count++;
            m=mid;
            m=m-a[mid];
        }
    }
    if(count>days) return false;
    else return true;
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    int sum=0;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int days;
    cin>>days;
    int y=INT_MIN;
    for(int i=0; i<n; i++){
        if(y<a[i]){y=a[i];}
        sum=sum+a[i];
    }
    int high=sum;
    int low=y;
    int maxcapacity=sum;
    while(high>=low){
        int mid=low+(high-low)/2;
        if(check(mid,a,days)){
            maxcapacity=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    cout<<maxcapacity;
}