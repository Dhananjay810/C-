#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    freopen("input80.txt","r",stdin);
    freopen("output80.txt","w",stdout);
    int boy;
    cin>>boy;
    int girl;
    cin>>girl;
    int mx,mi;
    bool flag;
    if(boy>girl){
        flag=true;
        mx=boy;
        mi=girl;
    }
    else{
        flag=false;
        mx=girl;
        mi=boy;
    }
    string s="";
    int i=0;
    if(flag==true){
        while(mi>0){
            if(i%2==0){
                s=s+"B";
                mx--;
            }
            else{
                s=s+"G";
                mi--;
            }
            i++;
        }
        while(mx>0){
            s=s+"B";
            mx--;
        }
    }
    else{
        while(mi>0){
            if(i%2==0){
                s=s+"G";
                mx--;
            }
            else{
                s=s+"B";
                mi--;
            }
            i++;
        }
        while(mx>0){
            s=s+"G";
            mx--;
        }
    }
    cout<<s;
}