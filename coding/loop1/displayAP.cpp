#include<iostream>
using namespace std;
int main(){
    int a;
    int d;
    int n;

    cout<<"enter first no. commen diff. and nth :";
        cin>>a;
        cin>>d;
        cin>>n;
    int i=1;
    while(i<=n){
        cout<<a+(i-1)*d;
        cout<<endl;
        i++;
    }
}