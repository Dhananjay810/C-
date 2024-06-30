#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool check(vector<int> v,int g){
    int n=v.size();
    bool flag=false;
    for(int i=0; i<n; i++){
        if(v[i]<=g) flag=true;
        else {
            flag=false;
            break;
        }
    }
    if(flag==true) return true;
    else return false;
}
int count(vector<int> d,int n){
    int e=n-1;
    for(int i=0; i<n; i++){
        if(d[i]>0) e=i;
    }
    return e;
}
int main(){
    int n;
    cin>>n;
    int g;
    cin>>g;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        int u;
        cin>>u;
        if(u>g) a[i]=u;
        else a[i]=0;
    }
    for(int i=1; i>0; i++){
        if(check(a,g)){
            cout<<count(a,n)+1;
            break;
        }
        else{
            for(int i=0; i<n; i++){
                a[i]=a[i]-g;
            }
        }
    }
    
}