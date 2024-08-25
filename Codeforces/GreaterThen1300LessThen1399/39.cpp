#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    int ze=0;
    int po=0;
    int ne=0;
    for(int i=0;i<n;i++){
        cin>>v[i];
        if(v[i]>0) po++;
        else if(v[i]<0) ne++;
        else ze++;
    }
    sort(v.begin(),v.end());
    int idx=-1;
    for(int i=0; i<n; i++){
        if(v[i]==0) idx=i;
    }
    cout<<"1"<<" "<<v[0]<<endl;
    ne--;
    if(ne==0){
        cout<<po<<" ";
        for(int i=idx+1; i<n; i++) cout<<v[i]<<" ";
        cout<<endl;
        cout<<"1"<<" "<<"0";
    }
    else{
        if(ne%2==0){
            cout<<po+ne<<" ";
            for(int i=1; i<n; i++){
                if(i!=idx) cout<<v[i]<<" ";
            }
            cout<<endl;
            cout<<"1"<<" "<<"0";
        }
        else{
            cout<<po+ne-1<<" ";
            for(int i=2; i<n; i++){
                if(i!=idx) cout<<v[i]<<" ";
            }
            cout<<endl;
            cout<<"2"<<" "<<v[1]<<" "<<"0";
        }
    }
}