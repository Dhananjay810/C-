#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter side : ";
    cin>>n;
    int d=2;
    int a=1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout<<(a)+(j-1)*d;
        }
        cout<<endl;

    }
}