#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int c=0;

int rev(vector<int>& a,vector<int>& b){
    int i=0,j=0;
    int count=0;
    while(i<a.size() && j<b.size()){
        if((long long)a[i]>(long long)2*b[j]){
            count+=a.size()-i;
            j++;
        }
        else i++;
    }
    return count;
}

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

    c=c+rev(a,b);

    mergeArr(a,b,v);
    // till now SC = O(nlogn)

    a.clear();
    b.clear();    

    // now SC is O(n)
}
int main(){
    vector<int> a={2,4,3,5,1};
    for(int i=0; i<a.size(); i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    merge(a);
    // for(int i=0; i<a.size(); i++){
    //     cout<<a[i]<<" ";
    // }
    cout<<c;
}