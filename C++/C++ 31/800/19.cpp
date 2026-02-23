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
        int ev=0;
        int od=0;
        int ans=0;
        for(int i=0; i<n; i++){
            cin>>v[i];
            ans+=v[i];
            if(v[i]<0) od++;
            else ev++;
        }
        if(od<=ev && od%2==0) cout<<"0"<<endl;
        else{
            int op=0;
            while(od>ev){
                od--;
                ev++;
                op++;
            }
            if(od%2==0){
                cout<<op<<endl;
            }
            else{
                cout<<op+1<<endl;
            }
        }
    }
}