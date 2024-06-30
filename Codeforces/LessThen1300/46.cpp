#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    int m,n;
    cin>>m>>n;
    int a[m];
    int y=0;
    for(int i=0; i<m; i++){
        cin>>a[i];
        if(a[i]<0) y++;
    }
    int b[y];
    int o=0;
    for(int i=0; i<m; i++){
        if(a[i]<0){
            b[o]=a[i]*(-1);
            o++;
        }

    }
    // for(int i=0; i<y; i++){
    //     cout<<b[i]<<" ";
    // }
    int temp=0;
    for(int i=0; i<y; i++){
        for(int j=0; j<y-i; j++){
            if(b[j]>b[j+1] && j!=y-1){
                temp=b[j];
                b[j]=b[j+1];
                b[j+1]=temp;
            }
        }
    }
    // cout<<endl;
    // for(int i=0; i<y; i++){
    //     cout<<b[i]<<" ";
    // }
    int f=1,e=0;
   for(int i=y-1; i>=0; i--){
        e=e+b[i];
        f++;
        if(f<=n) continue;
        else break;
   }
//    cout<<endl;
   cout<<e;

}