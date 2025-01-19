#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> v;
    int ne=0;
    int pos=0;
    for(int i=0; i<n; i++){
        int num;
        cin>>num;
        v.push_back(num);
        if(num<0) ne++;
        else pos++;
    }
    sort(v.begin(),v.end());
    int ans=0;
    for(int i=0; i<n; i++){
        if(v[i]<0) ans=ans+((-1)*(v[i]));
        else ans+=v[i];
    }
    if(ne==0){
        if(k==0){
            cout<<ans<<endl;
            return 0;
        }
        if(k%2==0){
            cout<<ans<<endl;
            return 0;
        }
        else{
            cout<<ans-(2*v[0])<<endl;
            return 0;
        }
    }
    
    if(k<ne){
        int gg=0;
        for(int i=0; i<n; i++){
            if(i<k) gg+=(-1)*(v[i]);
            else gg+=v[i];
        }
        cout<<gg;
        return 0;
    }

    int fineg=ne-k;

    if(ne==k){
        cout<<ans;
        return 0;
    }

    int mi=INT_MAX;
    for(int i=0; i<n; i++){
        if(v[i]<0) mi=min(mi,(-1)*(v[i]));
        else mi=min(mi,v[i]);
    }

    if(fineg%2!=0) cout<<ans-(2*mi);
    else cout<<ans;

}