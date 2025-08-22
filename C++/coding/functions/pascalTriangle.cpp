#include<iostream>
using namespace std;
int fact(int x){
    int f=1;
    for(int h=2; h<=x; h++){
        f=f*h;
    }
    return f;
}

int main(){
    int n;
    cout<<"enter side of triangle : ";
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
                int y=fact(i);
            int u=fact(j);
                int p=fact(i-j);
            int r=y/(u*p);
                 cout<<r<<" ";
            

        }
        cout<<endl;

}

}