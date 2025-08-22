#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    int k,x;
    cin>>k>>x;
    vector<int> ans(k);
    if(x<v[0]){
        for(int i=0; i<k; i++){
            ans[i]=v[i];
        }
    }
    if(x>v[n-1]){
        for(int j=k-1; j>=0; j--){
            int i=n-1;
            ans[j]=v[i];
            i--;
        }
    }
    int low=0;
    int high=n-1;
    bool flag=false;
    int mid=-1,t=0;
    while(high>=low){
        mid=low+(high-low)/2;
        if(v[mid]==x){
            flag=true;
            ans[t]=v[mid];
            t++;
            break;
        }
        else if(v[mid]<x) low=mid+1;
        else high=mid-1;
    }
    int lb=high;
    int ub=low;
    if(flag==true){
        int lb=mid-1;
    int ub=mid+1;
    }
    while(t<k && lb>=0 && ub<=n-1){
        int d1=abs(x-v[lb]);
        int d2=abs(x-v[ub]);
        if(d1<=d2){
            ans[t]=v[lb];
            lb--;
            t++;
        }
        else{
            ans[t]=v[ub];
            ub++;
            t++;
        }
    }
    if(lb<0){
        while(t<k){
            ans[t]=v[ub];
            ub++;
            t++;
        }
    }
    if(ub>n-1){
        while(t<k){
            ans[t]=v[lb];
            lb--;
            t++;
        }
    }
    for(int i=0; i<k; i++){
        cout<<ans[i]<<" ";
    }

}