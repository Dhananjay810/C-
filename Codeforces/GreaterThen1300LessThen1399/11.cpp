#include<iostream>
#include<vector>
using namespace std;
int main(){
    long long x,y;
    cin>>x>>y;
    long long a=0;
    if(x>0 && y>0){
        a=x+y;
        cout<<"0"<<" "<<a<<" "<<a<<" "<<"0";
    }
    else if(x<0 && y>0){
        a=-x+y;
        int b=-1*a;
        cout<<b<<" "<<0<<" "<<0<<" "<<a;
    }
    else if(x<0 && y<0){
        a=-x-y;
        cout<<((-1)*a)<<" "<<"0"<<" "<<"0"<<" "<<(-1)*a;
    }
    else if(x>0 && y<0){
        a=x-y;
        cout<<"0"<<" "<<(-1)*a<<" "<<a<<" "<<"0";
    }
}