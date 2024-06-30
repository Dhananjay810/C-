#include<iostream>
#include<climits>
using namespace std;
int main(){
    int s;
    cin>>s;
    int n;
    cin>>n;
    int a[n][2];
    for(int i=0; i<n; i++){
        for(int j=0; j<2; j++){
            cin>>a[i][j];
        }
    }
    bool flag=false;
    for(int i=0; i<n; i++){
        int c=INT_MAX;
        int t=-1;
        for(int j=0; j<n; j++){
            if(c>a[j][0]){
                c=a[j][0];
                t=j;
            }
        }
      //  cout<<c<<" ";
        if(s>c){
            s=s+a[t][1];
            a[t][0]=INT_MAX;
            flag=true;
        }
        else{
             flag=false;
             }
    }
    if(flag==true) cout<<"YES";
    else if(flag==false) cout<<"NO";
}