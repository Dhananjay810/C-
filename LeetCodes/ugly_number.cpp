#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
bool prime(int u) { // 2 and 3 are prime numbers
    if (u % 2 == 0 || u % 3 == 0) return false; // Exclude multiples of 2 and 3

    for (int i = 5; i * i <= u; i += 6) {
        if (u % i == 0 || u % (i + 2) == 0) return false;
    }
    return true;
}
int main(){
    int n;
    cin>>n;
    if(n<=6) cout<<n;
    else{
        long long count=6;
        long long h=8;
        long long g=6;
        while(count<n){
            bool flag=false;
            long long u=7;
            if(prime(h)==true){
                    flag=true;
                }
                else{
            while(u<=h){
                if(prime(u)==true){
                    if(h%u==0){
                        flag=true;
                        break;
                    }
            }
            u++;
        }
        }
        if(flag==false){
            count++;
            g=h;
        }
        h++;
        }
        cout<<g;
    }
}