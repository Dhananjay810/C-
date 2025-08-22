#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool ch(vector<int>& v,int d,int i){
    if(v.size()==0) return false;
    int count=0;
    for(int k=0; k<v.size(); k++){
        if(v[k]==d) count++;
    }
    if(count<i) return false;
    return true;
}

int main(){
    vector<int> nums1={9,9,1,1,1};
    vector<int> nums2={5,5,5};
    sort(nums1.begin(),nums1.end());
    //sort(nums2.begin(),nums2.end());
    int n1=nums1.size();
    int n2=nums2.size();
    vector<int> v;
    for(int i=0; i<n2; i++){
        for(int j=0; j<n1; j++){
            int d=nums2[i]-nums1[j];
            if(ch(v,d,i)==false){
            v.push_back(d); 
            }
           }
    }
    //sort(v.begin(),v.end());
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    // int u=1;
    // int i=0;
    // while(i<v.size()){
    //     if(v[i]==v[i+1]) u++;
    //     else{
    //         u=1;
    //     }
    //     if(u==n2) break;
    //     i++;
    // }
    // cout<<endl<<v[i];
}