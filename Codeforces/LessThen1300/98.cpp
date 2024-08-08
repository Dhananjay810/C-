#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    int idx1=-1;
    int idx2=-1;
    bool flag=false;
    for(int i=0; i<n-1; i++){
        if(flag==false && v[i]>=v[i+1]){
            idx1=i;
            flag=true;
        }
        if(flag==true && v[i]<=v[i+1]){
            idx2=i;
            break;
        }
    }
    if(idx1==-1){
        cout<<"yes"<<endl;
        cout<<1<<" "<<1;
        return 0;
    }
    if(idx2==-1) idx2=n-1;

    for(int i=0; i<idx1; i++){
        if(v[i]>=v[idx2] && v[i]<=v[idx1]){
            cout<<"no"<<endl;
            return 0;
        }
    }

    for(int i=idx2+1; i<n; i++){
        if(v[i]>=v[idx2] && v[i]<=v[idx1]){
            cout<<"no"<<endl;
            return 0;
        }
    }

    for(int i=idx2+1; i<n-1; i++){
        if(v[i]>v[i+1]){
            cout<<"no";
            return 0;
        }
    }

    cout<<"yes"<<endl;

    cout<<idx1+1<<" "<<idx2+1;
}