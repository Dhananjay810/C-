#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int inversion(vector<int>& a,vector<int>& b){
    int i=0,j=0;
    int count=0;
    while(i<a.size() && j<b.size()){
        if(a[i]>2*b[j]){
            count += a.size()-i;
            j++;
        }
        else i++;
    }
    return count;
}

void marge(vector<int>& a,vector<int>& b, vector<int>& v){
    int i=0,j=0,k=0;
    while(i<a.size() && j<b.size()){
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


int merge(vector<int>& nums){
    int count=0;
    if(nums.size()==1) return 0;
    int n=nums.size();
    int n1=n/2;
    int n2=n-n/2;
    vector<int> a(n1);
    vector<int> b(n2);
    for(int i=0; i<n1; i++){
        a[i]=nums[i];
    }
    for(int i=0; i<n2; i++){
        b[i]=nums[i+n1];
    }
    count+=merge(a);
    count+=merge(b);
    // count inversion
    count+= inversion(a,b);
    marge(a,b,nums);
    return count;
}
int main(){
    vector<int> nums={2,4,3,5,1};
    for(int i=0; i<nums.size(); i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    cout<<merge(nums);
}