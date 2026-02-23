#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        bool anna=true;
        if(c%2!=0){
            anna=false;
        }
        if(anna==false){
            b--;
            anna=true;
        }
        if(a<=b){
            cout<<"Second"<<endl;
        }
        else cout<<"First"<<endl;
    }
}