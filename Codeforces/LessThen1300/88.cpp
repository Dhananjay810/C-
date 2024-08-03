#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<vector<char>> v(4,vector<char>(4));
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++) cin>>v[i][j];
    }
    bool flag=false;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            int b=0;
            int w=0;
            if(v[i][j]=='#') b++;
            else w++;
            if(v[i][j+1]=='#') b++;
            else w++;
            if(v[i+1][j]=='#') b++;
            else w++;
            if(v[i+1][j+1]=='#') b++;
            else w++;
            if(b==1 || w==1){
                cout<<"YES";
                return 0;
            }
            if(b==4 || w==4){
                cout<<"YES";
                return 0;
            }
        }
    }
    cout<<"NO";
}