#include<iostream>
#include<vector>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0; i<n; i++) cin>>v[i];
        int ans=0;
        int count=0;
        bool flag=false;
        for(int i=0; i<n; i++){
            if(v[i]%2==0){
                if(flag==false){
                    if(count>0) ans+=(count-1);
                    count=1;
                    flag=true;
                }
                else count++;
            }
            else{
                if(flag==true){
                    if(count>0) ans+=(count-1);
                    count=1;
                    flag=false;
                }
                else count++;
            }
        }
        if(count!=0) ans+=(count-1);
        cout<<ans<<endl;
    }
}