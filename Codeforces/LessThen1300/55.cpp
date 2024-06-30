#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int h,t;
    int nn=0;
    for(int i=0; i<=n; i++){
        h=0;
        for(int j=0; j<n+1+nn; j++){
            if(j<n-i) cout<<" ";
            else{
                if(j<=n)
                {cout<<h;
                h++;}
                else if(j>n){
                    t=h-2;
                    cout<<t;
                    h--;
                }
            }
            if(j!=n+nn){
            cout<<" ";}
        }
        nn++;
        cout<<endl;
    }
    int g,f;
    int bb=1;
   for(int i=n-1; i>=0; i--){
    g=0;
    for(int j=0; j<(2*n+1)-bb; j++){
        if(j<n-i) cout<<" ";
        else{
            if(j<=n){
                cout<<g;
                g++;
            }
            else if(j>n){
                f=g-2;
                cout<<f;//<<" ";
                g--;
            }
        }
        if(j!=2*n-bb){
        cout<<" ";}
    }
    bb++;
    cout<<endl;
   }
}