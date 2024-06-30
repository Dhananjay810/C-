#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int r;
    cin>>r;
    int c;
    cin>>c;
    vector<vector<char>>cake(r,vector<char>(c));
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin>>cake[i][j];
        }
    }
    vector<int>k;
    for(int i=0; i<r; i++){
        int h=0;
        for(int j=0; j<c; j++){
            if(cake[i][j]=='S'){
                h=0;
                break;
            }
            else if(cake[i][j]=='.') h++;
        }
        k.push_back(h);
        if(h!=0){
            for(int j=0; j<c; j++){
                cake[i][j]='#';
            }
        }
    }

    for(int i=0; i<c; i++){
        int h=0;
        for(int j=0; j<r; j++){
            if(cake[j][i]=='S'){
                h=0;
                break;
            }
            else if(cake[j][i]=='.') h++;
        }
        k.push_back(h);
        if(h!=0){
            for(int j=0; j<r; j++){
                cake[j][i]='#';
            }
        }
    }
    int t=0;
    for(int i=0; i<k.size(); i++){
        t=t+k[i];
    }
    cout<<t;
}