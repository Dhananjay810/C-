#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    // for(int i=0; i<n; i++){
    //     cout<<a[i];
    // }
    for(int i=1; i<n; i++){
        int j=i;
        // while(j>=1){
        //     if(a[j]>=a[j-1]) break;
        //     else
        //         swap(a[j],a[j-1]);
        //     j--;
        // }
        while(a[j]<a[j-1] && j>=1){
            swap(a[j],a[j-1]);
            j--;
        }
    }
    cout<<endl;
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }

}