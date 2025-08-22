#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    int y=0;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=0; i<n-1; i++){
        if(a[i]<=a[i+1]){y=1;
            continue;
            
        }
        else {
            cout<<"NO";
            y=0;
            break;
        }
    }
    if(y==1)
    cout<<"YES";
}