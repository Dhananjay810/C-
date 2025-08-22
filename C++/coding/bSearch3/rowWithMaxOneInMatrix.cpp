#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>a[i][j];
        }
    }
    bool flag=false;
    vector<int> v(n);
    if(n==1){
        cout<<a[0][0];
    }
    else
    {for(int i=0; i<n; i++){
        int low=0;
        int high=n-1;
        int idx=-1;
        int z=0;
        bool flag=false;
        while(high>=low){
            int mid=low+(high-low)/2;
            if(a[i][mid]==z){
                if(a[i][mid+1]==z) low=mid+1;
                else{
                    v[i]=n-mid-1;
                    flag=true;
                    break;
                }
            }
            else if(a[i][mid]>z) high=mid-1;
            else low=mid+1;
        }
        if(flag==false) v[i]=n;
    }
    int l=v[0];
    int g=-1;
    for(int i=0; i<n; i++){
        if(l<v[i]){
            l=v[i];
            g=i;
        }
    }
    cout<<g;}
}