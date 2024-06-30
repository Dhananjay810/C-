#include<iostream>
using namespace std;
int fact(int x){
    int f=1;
    for(int i=2; i<=x; i++)
    {
        f=f*i;
    }
    return f;
}
int main(){
    int n; 
    cout<<"enter n : ";
    cin>>n;
    int r;
    cout<<"enter r : ";
    cin>>r;
    int y=fact(n);
    int z=fact(r);
    int m=fact(n-r);

    int s=y/(z*m);

    cout<<s;
}