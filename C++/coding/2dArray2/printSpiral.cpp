#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int m,n;
    cout<<"enter row and column : ";
    cin>>m>>n;
    int a[m][n];
    cout<<"enter value : ";
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>a[i][j];
        }
    }
    vector<int> mm;
    int minr=0,minc=0;
    int maxr=m-1;
    
    int maxc=n-1;
    while(minr<=maxr && minc<=maxc){
    for(int j=minc; j<=maxc; j++){
        cout<<a[minr][j]<<" ";
        mm.push_back(a[minr][j]);
    }
    minr++;
    if(minr>maxr || minc>maxc) break;
    for(int i=minr; i<=maxr; i++){
         mm.push_back(a[i][maxc]);
        cout<<a[i][maxc]<<" ";
       
    }
    maxc--;
    if(minr>maxr || minc>maxc) break;
    for(int j=maxc; j>=minc; j--){
        mm.push_back(a[maxr][j]);
        cout<<a[maxr][j]<<" ";
        
    }
    maxr--;
    if(minr>maxr || minc>maxc) break;
    for(int i=maxr; i>=minr; i--){ 
        mm.push_back(a[i][minc]);
        cout<<a[i][minc]<<" ";
       
    }
    minc++;
    }
    cout<<endl;
    for(int bb=0; bb<m*n; bb++){
        cout<<mm[bb]<<" ";
    }
}