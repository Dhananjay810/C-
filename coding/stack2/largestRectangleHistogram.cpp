#include<iostream>
#include<stack>
using namespace std;
int main(){
    int arr[]={2,1,5,6,2,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    stack<int> nse;
    stack<int> pse;
    int ans[n];
    nse.push(n-1);
    ans[n-1]=-1;
    for(int i=n-2; i>=0; i--){
        while(nse.size()>0 && arr[nse.top()]>=arr[i]) nse.pop();
        if(nse.size()==0) ans[i]=-1;
        else ans[i]=nse.top();
        nse.push(i);
    }
    int ans2[n];
    pse.push(0);
    ans2[0]=-1;
    for(int i=1; i<n; i++){
        while(pse.size()>0 && arr[pse.top()]>=arr[i]) pse.pop();
        if(pse.size()==0) ans2[i]=-1;
        else ans2[i]=pse.top();
        pse.push(i);
    }
    int final[n];
    for(int i=0; i<n; i++){
        int u=arr[i];
        if(ans[i]==-1 && ans2[i]==-1){
            final[i]=u*n;
        }
        else if(ans[i]==-1 || ans2[i]==-1){
            if(ans[i]==-1){
                final[i]=u*(n-ans2[i]-1);
            }
            else{
                final[i]=u*(ans[i]);
            }
        }
        else{
            final[i]=u*(ans[i]-ans2[i]-1);
        }
    }
    int k=-1;
    for(int i=0; i<n; i++){
        if(k<final[i]) k=final[i];
    }
    cout<<k;
}