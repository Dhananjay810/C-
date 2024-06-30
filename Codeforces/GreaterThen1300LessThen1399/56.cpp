#include<iostream>
#include<climits>
using namespace std;
int main(){
    int arr[5];
    for(int i=0; i<5; i++) cin>>arr[i];
    string s;
    cin>>s;
    

    int x=arr[3]-arr[1];
    int y=arr[4]-arr[2];
    int ax=abs(arr[3]-arr[1]);
    int ay=abs(arr[4]-arr[2]);
    char cx,cy;
    if(x>0){
        cx='E';
    }
    else cx='W';

    if(y>0) cy='N';
    else cy='S';
    int idx=-1;
    //cout<<ax<<" "<<ay<<" "<<cx<<" "<<cy<<endl;
    for(int i=0; i<s.size(); i++){
        if(s[i]==cx && ax!=0) ax--;
        if(s[i]==cy && ay!=0) ay--;

        if(ax==0 && ay==0){
            idx=i;
            break;
        }
    }
    //cout<<ax<<" "<<ay<<" "<<cx<<" "<<cy<<endl;
    if(ax!=0 || ay!=0){
        cout<<"-1";
        return 0;
    }
    cout<<idx+1;
}