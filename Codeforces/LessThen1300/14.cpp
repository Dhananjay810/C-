#include<iostream>
#include<climits>
using  namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int x=-1,y=-1;
    int c=INT_MIN;
    int d=INT_MAX;
    for(int i=0; i<n; i++){
        if(c<a[i]){
            c=a[i];
            x=i;
        }
    }
    for(int i=n-1; i>=0; i--){
        if(d>a[i]){
            d=a[i];
            y=i;
        }
    }
    if(x>y) cout<<(x)+(n-1-y)-1;
    else cout<<(x)+(n-1-y);
    
    
}