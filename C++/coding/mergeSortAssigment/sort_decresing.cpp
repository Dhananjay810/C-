#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void marge(vector<int>& a,vector<int>& b,vector<int>& v){
    int i=0,j=0,k=0;
    while(i<a.size() && j<b.size()){
        if(a[i]<b[j]){
            v[k]=b[i];
            j++;
            k++;
        }
        else{
            v[k]=a[j];
            i++;
            k++;
        }
    }
    if(i==a.size()){
        while(j<b.size()){
            v[k]=b[j];
            j++;
            k++;
        }
    }
    if(j==b.size()){
        while(i<a.size()){
            v[k]=a[i];
            i++;
            k++;
        }
    }
}

void merge(vector<int>& v){
    int n=v.size();
    if(n==1) return;
    int n1=n/2,n2=n-n/2;
    vector<int> a(n1);
    vector<int> b(n2);
    for(int i=0; i<n1; i++){
        a[i]=v[i];
    }
    for(int i=0; i<n2; i++){
        b[i]=v[i+n1];
    }
    merge(a);
    merge(b);

    marge(a,b,v);
}
int main(){
    vector<int> v={4,8,6,2,1,7,6};
    for(int i=0; i<v.size(); i++) cout<<v[i]<<" ";
    cout<<endl;
    merge(v);
    for(int i=0; i<v.size(); i++) cout<<v[i]<<" ";
}