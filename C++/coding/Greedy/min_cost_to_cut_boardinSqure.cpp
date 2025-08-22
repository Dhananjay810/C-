#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int mincost(int m,int n,vector<int> &horizontal, vector<int> &vertical){
    sort(horizontal.begin(),horizontal.end());
    sort(vertical.begin(),vertical.end());
    reverse(horizontal.begin(),horizontal.end());
    reverse(vertical.begin(),vertical.end());
    int h=0,v=0;
    int hb=1,vb=1;
    int ans=0;
    while(h<horizontal.size() and v<vertical.size()){
        if(horizontal[h]<vertical[v]){
            ans+=vertical[v]*vb;
            hb++;

            v++;
        }
        else{
            ans+=horizontal[h]*hb;
            vb++;
            h++;
        }
    }
    while(h<horizontal.size()){
        ans+=horizontal[h]*hb;
        vb++;
        h++;
    }
    while(h<horizontal.size()){
        ans+=vertical[v]*vb;
            hb++;

            v++;
    }
    return ans;
}
int main(){
    int m,n;
    vector<int> horizontal;
    vector<int> vertical;
    
}