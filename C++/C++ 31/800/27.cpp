#include<iostream>
#include<vector>
using namespace std;;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        vector<int> h(n);
        for(int i=0; i<n; i++){
            cin>>v[i];
            if(i==0){
                if(v[i]==2) h[i]=1;
                else h[i]=0;
            }
            else{
                if(v[i]==2) h[i]=h[i-1]+1;
                else h[i]=h[i-1];
            }
        }
        bool flag=false;
        for(int i=0; i<n; i++){
            
            if(h[i]==(h[n-1]-h[i])){
                cout<<i+1<<endl;
                flag=true;
                break;
            }
        }
        if(flag==false) cout<<"-1"<<endl;
    }
}