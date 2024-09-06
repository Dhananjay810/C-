#include<iostream>
#include<stack>
using namespace std;
int main(){
    int arr[]={11,19,12,15,14,18,7,1,8,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    int nge[n];
    stack<int> st;
    nge[n-1]=-1;
    st.push(n-1);
    for(int i=n-2; i>=0; i--){
        int k=0;
        while(st.size()>0 && arr[st.top()]<=arr[i]){
            st.pop();
            k++;
        }
        if(st.size()!=0) k++;
        nge[i]=k;
        st.push(i);
    }
    nge[n-1]=0;
    for(int i=0; i<n; i++) cout<<nge[i]<<" ";
    // cout<<endl;
    // int ans[n];
    // for(int i=0; i<n-1; i++){
    //     int f=1;
    //     for(int j=i+1; j<nge[i]; j++){
    //         if(nge[j]!=-1){
    //             f++;
    //             j=nge[j]-1;
    //         }
    //     }
    //     ans[i]=f;
    // }
    // ans[n-1]=0;
    // for(int i=0; i<n;  i++) cout<<ans[i]<<" ";
}