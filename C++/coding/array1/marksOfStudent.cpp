#include<iostream>
using namespace std;
int main(){
    int m;
    cout<<"enter size : ";
    cin>>m;
    int marks[m];
    
    cout<<"enter marks : ";
    
    for( int i =0; i<m-1; i++){
        cin>>marks[i];

    }

    for(int i =0; i<=m-1; i++){
        if(marks[i]<35){
            cout<<i<<" ";
        }
    }

  }
    
