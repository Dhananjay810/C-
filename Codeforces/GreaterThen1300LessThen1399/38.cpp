#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

bool isLucky(int n){
    while(n!=0){
        int r = n%10;
        n=n/10;
        if(r!=4 && r!=7) return false;
    }
    return true;
}

int main(){
    int n;
    cin>>n;
    
    if(isLucky(n)==true){
        cout<<"YES";
        return 0;
    }

    int j;
    for(j=2; j<=sqrt(n); j++){
        if(n%j==0){
            if(isLucky(j)==true){
                cout<<"YES";
                return 0;
            }
            // cout<<j<<" ";
        }
    }


    for(j=sqrt(n); j>=1; j--){
        if(n%j==0){
            if(isLucky(n/j)==true){
                cout<<"YES";
                return 0;
            }
            // cout<<n/j<<" ";
        }
    }

    cout<<"NO";

}