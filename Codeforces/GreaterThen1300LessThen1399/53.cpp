#include<iostream>
#include<vector>
#include<cmath>
#include<unordered_map>
using namespace std;
int main(){
    int n;
    cin>>n;
    unordered_map<int,int> m;
    for(int i=0; i<n; i++){
        int num;
        cin>>num;
        m[num]++;
    }
    if(m.find(7)!=m.end()){
        cout<<"-1";
        return 0;
    }
    if(m.find(5)!=m.end()){
        cout<<"-1";
        return 0;
    }
    int u=m[2]+m[3];
    if(m[1]!=u){
        cout<<"-1";
        return 0;
    }
    if(m[2]<m[4]){
        cout<<"-1";
        return 0;
    }
    int a=m[4];
    int b=m[2];
    int c=b-a;
    int h=m[3]+c;
    if(h!=m[6]){
        cout<<"-1";
        return 0;
    }

    int x=m[4];
    for(int i=0; i<x; i++){
        cout<<"1"<<" "<<"2"<<" "<<"4"<<endl;
        m[1]--;
        m[2]--;
    }
    // if(m[2]==0) m.erase(2);
    m.erase(4);

    int g=m[6];
    int gg=m[2];
    for(int i=0; i<gg; i++){
        cout<<"1"<<" "<<"2"<<" "<<"6"<<endl;
        m[6]--;
        m[1]--;
    }
    g=m[6];
    for(int i=0; i<g; i++){
        cout<<"1"<<" "<<"3"<<" "<<"6"<<endl;
    }
}