#include<iostream>
#include<vector>
using namespace std;
void disp(int arr[],int n,int idx){
    if(idx==n) return;
    cout<<arr[idx]<<" ";
    disp(arr,n,idx+1);
}

void disp2(vector<int>& v,int idx){
    if(idx==v.size()) return;;
    cout<<v[idx]<<" ";
    disp2(v,idx+1);
}
int main(){
    int arr[]={3,4,5,76,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    //disp(arr,n,0);

    vector<int>v(n);
    for(int i=0; i<n; i++){
        v[i]=arr[i];
    }
    disp2(v,0);
} 