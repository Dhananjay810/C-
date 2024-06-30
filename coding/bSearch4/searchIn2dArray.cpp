#include<iostream>
using namespace std;
int main(){
    int m;
    cin>>m;
    int n;
    cin>>n;
    int a[m][n];
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>a[i][j];
        }
    }
    int h;
    cin>>h;
    bool flag=false;
    for(int i=0; i<m; i++){
        int low=0;
        int high=n-1;
        while(high>=low){
            int mid=low+(high-low)/2;
            if(a[i][mid]==h){
                cout<<"true";
                flag=true;
                break;
            }
            else if(a[i][mid]<h) low=mid+1;
            else high=mid-1;
        }
        if(flag==false) break;
    }
    if(flag==false) cout<<"false";
}
