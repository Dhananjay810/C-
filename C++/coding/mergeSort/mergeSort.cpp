#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void mergeArr(vector<int>& a,vector<int>& b,vector<int>& v){
    int n1=a.size(),n2=b.size();
    int i=0,j=0,k=0;
    while(i<n1 && j<n2){
        if(a[i]<b[j]){
            v[k]=a[i];
            i++;
            k++;
        }
        else{
            v[k]=b[j];
            j++;
            k++;
        }
    }
    if(i==n1){
        while(j<n2){
            v[k]=b[j];
            k++;
            j++;
        }
    }
    if(j==n2){
        while(i<n1){
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

    mergeArr(a,b,v);
    // till now SC = O(nlogn)

    a.clear();
    b.clear();

    // now SC is O(n)
}
int main(){
    vector<int> a={4,8,6,2,1,7,6};
    for(int i=0; i<a.size(); i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    merge(a);
    for(int i=0; i<a.size(); i++){
        cout<<a[i]<<" ";
    }
}