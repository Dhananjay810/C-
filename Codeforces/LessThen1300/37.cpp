#include<iostream>
using namespace std;
int main(){
    long long n;
    cin>>n;
    long long m;
    cin>>m;
    long long g;
    bool flag=false;
    if(n%2==0) flag=true;
    if(flag==true){
        if(m<=n/2){
            g=m*2-1;
        }
        else if(m>n/2){
            g=(m-n/2)*2;
        }
    }
    else if(flag==false){
        if(m<=n/2+1){
            g=m*2-1;
        }
        else if(m>n/2+1){
            g=(m-(n/2+1))*2;
        }
    }
    cout<<g;
}