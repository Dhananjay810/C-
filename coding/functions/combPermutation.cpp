#include<iostream>
using namespace std;
// int comb(int n, int r){
//     int y=1,z=1,e=1;
//     for(int i=2; i<=n; i++){
//         y=y*i;
//     }
//     for(int t=2; t<=r; t++){
//         z=z*t;
//     }
//     for(int m=2; m<=(n-r); m++){
//         e=e*m;
//     }
//     return y/(z*e);
//}
int fact(int x){
    int p;
    for(int i=2; i<=x; i++){
        p=p*i;

    }
    return p;
}



int main(){
    int n,r; 
    cout<<"enter the value of 'n' & 'r' : "; 
    cin>>n>>r;
    // cout<<comb(n,r);
    int y=fact(n);
    int z=fact(r);
    int m=fact(n-r);
    
    int j=y/(m*z);

    cout<<j;

}

