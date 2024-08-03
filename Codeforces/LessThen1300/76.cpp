#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> x(n);
    for(int i=0; i<n; i++) cin>>x[i];
    vector<int> y(m);
    for(int i=0; i<m; i++) cin>>y[i];
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    if(y[0]<=x[n-1]){
        cout<<-1;
        return 0;
    }
    if(n==1){
        if(2*x[0]>=y[0]) cout<<-1;
        else cout<<2*x[0];
    }
    else if(x[n-1]>=2*x[0]) cout<<x[n-1];
    else cout<<-1;
}