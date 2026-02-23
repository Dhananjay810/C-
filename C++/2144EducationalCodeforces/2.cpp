#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<unordered_set>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        unordered_set<int> set;
        int min_idx=INT_MAX;
        int max_idx=INT_MIN;
        for(int i=0; i<n; i++){
            cin>>v[i];
            set.insert(v[i]);
            if(v[i]==0){
                min_idx=min(min_idx,i);
                max_idx=max(max_idx,i);
            }
        }
        bool f=false;
        if(min_idx==max_idx){
            if(set.find(min_idx+1)==set.end()){
                f=true;
                v[min_idx]=min_idx+1;
                max_idx=INT_MIN;
                min_idx=INT_MAX;
            }
        }
        // int dist=(max_idx-min_idx)+1;
        // cout<<min_idx<<" "<<max_idx<<" ";
        int min_idxx=INT_MAX;
        int max_idxx=INT_MIN;
        for(int i=0; i<n; i++){
            if(v[i]!=i+1){
                min_idxx=min(min_idxx,i);
                max_idxx=max(max_idxx,i);
            }
        }
        if(f==false){
            min_idxx=min(min_idx,min_idxx);
            max_idxx=max(max_idx,max_idxx);
        }
        // cout<<min_idxx<<" "<<max_idxx<<" ";
        if(min_idxx==INT_MAX && max_idxx==INT_MIN){
            cout<<"0"<<endl;
            continue;
        }
        int distt=(max_idxx-min_idxx)+1;
        cout<<distt<<endl;
    }
}