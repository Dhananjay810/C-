#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int a[8];
    for(int i=0; i<8; i++){
        cin>>a[i];
    }
    int w=((a[1]*a[2])/a[6])/a[0];
    int l=(a[3]*a[4])/a[0];
    int s=(a[5]/a[7])/a[0];
    int y=0;
    if(w<l && w<s) y=w;
    else if(l<w && l<s) y=l;
    else y=s;
    cout<<y;
}