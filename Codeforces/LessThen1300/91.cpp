#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
    long long n;
    cin>>n;
    for(int i=0; i<n; i++){
        long long int a;
        cin>>a;
        int u=0;
        int j;
        for(j=2; j<sqrt(a); j++){
            if(a%j==0){
                u++;
                if(u>1){
                    cout<<"NO";
                    break;
                }
            }
        }
        if(u<=1)
        {for(j=sqrt(a); j>1; j--){
            if(a%j==0){
                u++;
                if(u>1){
                    cout<<"NO";
                    break;
                }
            }
        }}
        if(u==1) cout<<"YES";
        if(u==0) cout<<"NO";
        cout<<endl;
    }

    

}