#include<iostream>
#include<vector>
#include<climits>
using namespace std;
vector<int> seg;

void build(int arr[], int i, int lo, int hi){
    if(hi==lo){
        seg[i]=arr[lo];
        return;
    }
    int mid=(hi+lo)/2;
    build(arr,2*i+1,lo,mid);
    build(arr,2*i+2,mid+1,hi);
    seg[i]=min(seg[2*i+1],seg[2*i+2]);
}

int getMin(int i, int lo, int hi, int l, int r){
    if(r<lo || l>hi) return INT_MAX;
    if(lo>=l && hi<=r) return seg[i];
    int mid=(lo+hi)/2;
    return min(getMin(2*i+1,lo,mid,l,r),getMin(2*i+2,mid+1,hi,l,r));
}

int main(){
    int arr[]={1,4,2,8,6,4,9,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    seg.resize(4*n);
    build(arr,0,0,n-1);
    int l,r;
    cout<<endl<<"Enter Range : ";
    cin>>l>>r;
    cout<<getMin(0,0,n-1,l,r);
}