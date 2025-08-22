#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> nums(n);
        for(int i=0; i<n; i++) cin>>nums[i];
        int ans=0;
        for(int i=0; i<n; i++){
            if(nums[i]==0) ans+=1;
            else ans+=nums[i];
        }
        cout<<ans<<endl;
    }
}