#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    int n,m=0,s=0;
    cin>>n;
    int h=0;
    int array[n];
    for(int i=0; i<n; i++){
        cin>>array[i];
        if(array[i]==0){
            m++;
        }
        else s++;
    }
    int z=s;
    for(int i=0; i<z; i++){
        int d=0;
        d=s*5;
        if(d%9==0 && m!=0){
            h=1;
            for(int j=0; j<s; j++){
                cout<<"5";
            }
            for(int j=0; j<m; j++){
                cout<<"0";
            }
            break;
        }
        else{
            s=s-1;
           /// m=m+1;
            continue;
        }
    }
     if(h==0 && m!=0){
        cout<<"0";
    }
    else if(h==0 && m==0){
        cout<<"-1";
    }
   
}
