#include<iostream>
using namespace std;
int main(){
    int a;
    int r;
    int n;
    cout<<"enter a comman ratio and nth :";
    cin>>a>>r>>n;
    int i=1;
    int gp=a;
    while(i<=n){
        gp=gp*r;
        cout<<gp<<"  ";
        i++;
    }

}