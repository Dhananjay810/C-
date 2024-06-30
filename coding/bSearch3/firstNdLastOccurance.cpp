#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int y;
    cin>>y;
    int low=0;
        int high=n-1;
        vector<int> v(2);
        int idx=-1;
        bool flag=false;
        int i=0;
        while(high>=low){
            int mid=low+(high-low)/2;
            if(a[mid]==y){
                if(a[mid-1]==y) high=mid-1;
                else{
                    idx=mid;
                    v[i]=idx;
                    flag=true;
                    i=1;
                    break;
                }
            }
            else if(a[mid]<y) low=mid+1;
            else high=mid-1;
        }
        low=0;
        high=n-1;
        idx=-1;
        while(high>=low){
                int mid=low+(high-low)/2;
                if(a[mid]==y){
                    if(a[mid+1]==y) low=mid+1;
                    else{
                        idx=mid;
                        v[i]=idx;
                        break;
                    }
                }
                else if(a[mid]<y) low=mid+1;
                else high=mid-1;  
        }
        if(flag==false){
            v[0]=-1;
            v[1]=-1;
        }
        for(int i=0; i<2; i++){
            cout<<v[i]<<" ";
        }
}