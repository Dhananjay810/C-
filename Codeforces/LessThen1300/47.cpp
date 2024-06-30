#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    int count =0;
    for(int i=0; i<min(n,m); i++){
        float x,y;
        if((m*m)+(i*i*i*i)-2*(i*i)*(m)+i==n){
            x=i;
            y=(m)-i*i;
            if(x==(int)x && y==(int)y && min(x,y)>=0){
            count ++;
        }
        }
    }
    if(n==1 && m==1) cout<<"2";
    else cout<<count;
}