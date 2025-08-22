#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int partition(vector<int>& v,int si,int ei){
    int count=0;
    int pivotele=v[(si+ei)/2];
    for(int i=si; i<=ei; i++){
        if(i==(si+ei)/2) continue;
        if(v[i]<=pivotele) count++;
    }
    int pivoteidx=count+si;
    swap(v[(si+ei)/2],v[pivoteidx]);
    int i=si,j=ei;
    while(i<pivoteidx && j>pivoteidx){
        if(v[i]<=v[pivoteidx]) i++;
        if(v[j]>v[pivoteidx]) j--;
        else if(v[i]>v[pivoteidx] && v[j]<v[pivoteidx]){
            swap(v[i],v[j]);
            i++;
            j--;
        }
    }
    return pivoteidx;
}

int qselect(vector<int>& v,int si,int ei,int k){
    int pi=partition(v,si,ei);
    if(k==pi+1) return v[pi];
    else if(pi+1<k) return qselect(v,pi+1,ei,k);
    else return qselect(v,si,pi-1,k);
}
int main(){
    vector<int> v={0,0,0,2,7,9,7,8,11};
    int k=7;
    cout<<qselect(v,0,v.size()-1,k);
}