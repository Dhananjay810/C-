#include<iostream>
#include<vector>
using namespace std;
int c=0;
vector<int> merge(vector<int> &a, vector<int> &b){
    int i=0,j=0;
    vector<int> ans;
    while(i<a.size() && j<b.size()){
        if(a[i]<b[j]) ans.push_back(a[i++]);
        else  ans.push_back(b[j++]);
    }
    if(i==a.size()) while(j<b.size()) ans.push_back(b[j++]);
    if(j==b.size()) while(i<a.size()) ans.push_back(a[i++]);
    return ans;
}

int Inversion(vector<int> &a, vector<int> &b){
    int count = 0;
    int i=0,j=0;
    while(i<a.size() && j<b.size()){
        if(a[i]>b[j]){
            count+=(a.size()-i);
            j++;
        }
        else i++;
    }
    return count;
}

vector<int> mergeSort(vector<int> &nums){
    int n=nums.size();
    if(n==1) return nums;
    int n1=n/2;
    int n2=n-n1;
    vector<int> a(n1),b(n2);
    for(int i=0; i<n1; i++) a[i]=nums[i];
    for(int i=0; i<n2; i++) b[i]=nums[i+n1];
    vector<int> sorA=mergeSort(a);
    vector<int> sorB=mergeSort(b);
    
    //Count Inversion
    c+=Inversion(sorA,sorB);
    //Merge
    return merge(sorA,sorB);
}

int main(){
    vector<int> nums={5,1,3,0,4,9,6};
    vector<int> sorted = mergeSort(nums);
    // for(int i=0; i<nums.size(); i++) cout<<sorted[i]<<" ";
    cout<<c;
}