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
        vector<int> v(n);
        for(int i=0; i<n; i++){
            cin>>v[i];
        }
        if(n==2 && v[0]==v[1]){
            cout<<"NO"<<endl;
            continue;
        }
        int sum=v[0];
        bool flag=true;
        for(int i=1; i<n; i++){
            if(v[i]==sum){
                flag=false;
                break;
            }
            sum+=v[i];
        }
        if(flag==true){
            cout<<"YES"<<endl;
            for(int i=0; i<n; i++) cout<<v[i]<<" ";
            cout<<endl;
            continue;
        }
        sort(v.begin(),v.end());
        if(v[0]==v[n-1]){
            cout<<"NO"<<endl;
            continue;
        }
        int temp=v[0];
        v[0]=v[n-1];
        v[n-1]=temp;
        cout<<"YES"<<endl;
        for(int i=0; i<n; i++) cout<<v[i]<<" ";
        cout<<endl;
    }
}