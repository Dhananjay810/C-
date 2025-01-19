#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int m,n;
    cin>>m>>n;

    vector<vector<char>> v(m,vector<char>(n));

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++) cin>>v[i][j];
    }

    int sum=0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(v[i][j]=='W'){
                if(i!=0 && v[i-1][j]=='P'){
                    v[i-1][j]='.';
                    sum++;
                }
                else if(i!=m-1 && v[i+1][j]=='P'){
                    v[i+1][j]='.';
                    sum++;
                }
                else if(j!=0 && v[i][j-1]=='P'){
                    v[i][j-1]='.';
                    sum++;
                }
                else if(j!=n-1 && v[i][j+1]=='P'){
                    v[i][j+1]='.';
                    sum++;
                }
            }
        }
    }
    cout<<sum;
}