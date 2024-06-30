#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int partition(vector<int>& v,int si,int ei){
    int count=0;
    //int pivotele=v[si];
    int pivotele=v[(si+ei)/2];
    for(int i=si; i<=ei; i++){
        if(i==(si+ei)/2) continue;
        if(v[i]<=pivotele) count++;
    }
    int pivoteidx=count + si;
    swap(v[(si+ei)/2],v[pivoteidx]);
    int i=si,j=ei;
    while(i<pivoteidx && j>pivoteidx){
        if(v[i]<=v[pivoteidx]) i++;
        if(v[j]>v[pivoteidx]) j--;
        else if(v[i]>v[pivoteidx] && v[j]<=v[pivoteidx]){
            swap(v[i],v[j]);
            i++;
            j--;
        }
    }
    return pivoteidx;
}

void qsort(vector<int>& v,int si,int ei){
    if(si>=ei) return;
    
    int pi=partition(v,si,ei);

    qsort(v,si,pi-1);
    qsort(v,pi+1,ei);
}
int main(){
    vector<int> v={5,1,8,2,77,6,3,4};
    qsort(v,0,v.size()-1);
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
}