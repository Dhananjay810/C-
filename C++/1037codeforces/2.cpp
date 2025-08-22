#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> v(n);
        for(int i=0; i<n; i++) cin>>v[i];
        int ans=0;
        for(int i=0; i<n; i++){
            int j=i;
            bool flag=true;
            int y=k;
            while(j<n && y>0){
                if(v[j]==1){
                    flag=false;
                    break;
                }
                j++;
                y--;
            }
            if(flag==true && y==0){
                ans++;
                i+=k;
                // cout<<i<<" "<<ans<<endl;
            }
        }
        cout<<ans<<endl;
    }
}